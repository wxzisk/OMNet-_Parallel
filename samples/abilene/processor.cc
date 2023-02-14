/*
 * processor.cc
 *
 *  Created on: 2017年1月16日
 *      Author: Vincent
 *
 *  功能：
 *  1. 发送和接收packet，一个packet对应一个flit
 *  2. 不采用流控模型，每间隔相应时间直接发送数据
 *
 */


#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include "fat_tree_m.h"
#include "fat_tree.h"

using namespace omnetpp;


// Processor
class Processor : public cSimpleModule
{
  private:
    cMessage *selfMsgGenMsg; //产生flit定时，package产生按泊松分布或均匀分布
    cMessage *selfMsgSendMsg; //发送flit定时，每周期都检查buffer，再发送

    long numFlitSent;
    long numFlitReceived;
    int valid_num_Process;
    int num_packets;
    int packet_len = 1500;
    double packets_gap = 0.000000007;
    // cPar *TxRate;
    //long numDropped;
    //long flitByHop; //用于计算链路利用率

    cOutVector hopCountVector;
    cOutVector flitDelayTime;

    FatTreeMsg* OutBuffer[ProcessorBufferDepth]; //用于存放flit,输出flit的缓存

  public:
    Processor();
    virtual ~Processor();
  protected:
    virtual FatTreeMsg *generateMessage();
    virtual void forwardMessage(FatTreeMsg *msg);
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;


    // The finish() function is called by OMNeT++ at the end of the simulation:
    virtual void finish() override;
};

Define_Module(Processor);

Processor::Processor(){
    selfMsgGenMsg=nullptr;
    selfMsgSendMsg=nullptr;
}


Processor::~Processor(){
    cancelAndDelete(selfMsgGenMsg);
    cancelAndDelete(selfMsgSendMsg);
}

void Processor::initialize()
{
    // Initialize variables
    numFlitSent = 0;
    numFlitReceived = 0;
    valid_num_Process= 10;
    num_packets = 1000000;
    // TxRate = &par("TxRate");
    //numDropped = 0;
    //flitByHop = 0;

    hopCountVector.setName("hopCount");
    flitDelayTime.setName("flitDelayTime");

    if(getIndex() < valid_num_Process)
    {
        selfMsgSendMsg = new cMessage("selfMsgSendMsg");//注意顺序，先发送buffer里面的msg，再产生新的msg，这样一个flit需要2个周期才会发出去
        scheduleAt(0.0, selfMsgSendMsg);
    }
    
    // selfMsgGenMsg = new cMessage("selfMsgGenMsg");
    // scheduleAt(Sim_Start_Time, selfMsgGenMsg);

    // for(int i = 0; i < ProcessorBufferDepth; i++)
    //     OutBuffer[i] = nullptr;
    // FatTreeMsg *msg = generateMessage();
    // scheduleAt(0.0, msg);
}

void Processor::handleMessage(cMessage *msg)
{
    // double rate = TxRate->doubleValue();
    // if(getIndex() < getVectorSize()/2)
    if(msg->isSelfMessage())
    {
        EV <<"Processor" <<getIndex() << "selfMsgSendMsg"<<endl;
        // if(getIndex() == 1)
        if(numFlitSent < num_packets)
        {
            FatTreeMsg *newmsg = generateMessage();
            forwardMessage(newmsg);
            scheduleAt(simTime() + packets_gap, selfMsgSendMsg);
            numFlitSent++;
            //EV<< "Processor" <<getIndex() <<"send the NO." << i << "packet"<<endl;
        }
    }
    else
    {
        if(getIndex() < valid_num_Process)
        {
            FatTreeMsg *mymsg = check_and_cast<FatTreeMsg *>(msg);
            forwardMessage(mymsg);
        }
        else
        {
            delete msg;
        }
        
    }
}


FatTreeMsg* Processor::generateMessage()
{

    // Produce source and destination address
    //int current_ppid = getIndex();
    //int n = getVectorSize();//processor的数量
    //int destination_ppid = current_ppid + n/2;

    char msgname[packet_len];//初始分配的空间太小导致数据被改变!!!!!!!
    //sprintf(msgname, "Flit, From processor node %d to node %d", current_ppid, destination_ppid);

    // Create message object and set source and destination field.
    FatTreeMsg *msg = new FatTreeMsg(msgname);
    //msg->setSrc_ppid(current_ppid); //设置发出的processor编号
    //msg->setDst_ppid(destination_ppid); //设置接收的processor编号
    msg->setHopCount(6);
    //EV << msg << endl;
    return msg;
}

//processor转发的路由算法,processor只有一个port,直接转发出去即可
void Processor::forwardMessage(FatTreeMsg *msg)
{
    char str1[20]="port";
    strcat(str1,"$o");
    send(msg,str1);
}


void Processor::finish()
{
    // // This function is called by OMNeT++ at the end of the simulation.
    // EV << "Flit Sent: " << numFlitSent << endl;
    // EV << "Flit Received: " << numFlitReceived << endl;
    // //EV << "Dropped:  " << numDropped << endl;


    // recordScalar("flitSent", numFlitSent);
    // recordScalar("flitReceived", numFlitReceived);
    // //recordScalar("#flit dropped", numDropped);
    // //recordScalar("#flitByHop", flitByHop);


    // if(getIndex() == 0) {
    //     double timeSpend = (simTime().dbl() - Sim_Start_Time);
    //     double clockCycle = CLK_CYCLE;
    //     double timeCount = (simTime().dbl() - Sim_Start_Time) / (CLK_CYCLE); //注意，文本替换

    //     recordScalar("timeSpend", timeSpend);
    //     recordScalar("timeCount", timeCount);
    //     recordScalar("clockCycle", CLK_CYCLE);
    // }

}



