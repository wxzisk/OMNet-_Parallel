/*
 * router.cc
 *
 *  Created on: 2017年1月16日
 *      Author: Vincent
 */

#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include <math.h>
#include <ctime>
#include "fat_tree_m.h"
#include "fat_tree.h"

using namespace omnetpp;


/*************************************************
 * 实现功能：
 *
 * 1. 只实现路由功能
 * 2. 每个端口的输出带宽设为参数，以gap’个时钟周期向外发送数据。
 * 3. 数据从输入端口到输出端口需要overhead个时钟周期
 * 4. 内部包含每个输出端口的输出缓存（设为无限大，或100，多余数据丢弃）
 * 5. 设计两个缓存，输入缓存和输出缓存，数据进入路由器先保存到输入缓存，间隔overhead个时钟周期后，数据从输入缓存转移到输出缓存
 *
 * ***********************************************
 */


// 对Router进行建模
class Router : public cSimpleModule
{
  private:

    cMessage *selfMsgAlloc; //message仲裁定时信号
    cMessage *selfMsgForwardGap; //路由器向外发送数据的间隔

    //越早到的数据放在ID小的那边，规定好,0表示buffer中第一个出去的数据
    FatTreeMsg* InputBuffer[PortNum][RouterBufferDepth]; //输入缓冲
    FatTreeMsg* OutputBuffer[PortNum][RouterBufferDepth]; //输出缓冲
    const static int valid_num_Process= 30;
    // double forward_gap[10] = {0.00000001, 0.00000002, 0.00000003, 0.00000004, 0.00000005, 0.00000006, 0.00000007,0.00000008, 0.00000009, 0.00000010};
    // int delay_index;
    int k = 8;//k of fat-tree
    cOutVector inputBufferUtility;
    cOutVector outputBufferUtility;

  public:
    Router();
    virtual ~Router();
  protected:
    virtual void forwardMessage(FatTreeMsg *msg, int out_port_id);
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual FatTreeMsg* generateMessage(int hopCount);
    // The finish() function is called by OMNeT++ at the end of the simulation:
    virtual void finish() override;
};

Define_Module(Router);

Router::Router(){
    selfMsgAlloc = nullptr;
    selfMsgForwardGap = nullptr;
}

Router::~Router(){
    cancelAndDelete(selfMsgAlloc);
    cancelAndDelete(selfMsgForwardGap);
}

//接入层编号： 0 ~ k*k/2 - 1; 汇聚层编号 ：k*k/2 ~ k*k - 1； 核心层编号：k*k ~ 5/4*k*k-1;  
void Router::initialize()
{
    for(int i = 0; i < PortNum; i++) {
        for(int j = 0; j < RouterBufferDepth; j++) {
            InputBuffer[i][j] = nullptr;
            OutputBuffer[i][j] = nullptr;
        }
    }


    //对selfMsg进行初始化,保证selfMsgFrowardGap在selfMsgAlloc前面


    inputBufferUtility.setName("inputBufferUtility");
    outputBufferUtility.setName("outputBufferUtility");
}

FatTreeMsg* Router::generateMessage(int hopCount)
{
    char msgname[1500];//初始分配的空间太小导致数据被改变!!!!!!!

    FatTreeMsg *msg = new FatTreeMsg(msgname);
    msg->setHopCount(hopCount);
    return msg;
}

void Router::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage())
    {
        //do nothing
    }
    else
    {
        FatTreeMsg *mymsg = check_and_cast<FatTreeMsg *>(msg);
        int hop_left = mymsg -> getHopCount();
        EV<<hop_left<<endl;
        if(hop_left == 0 && getIndex() >= valid_num_Process)
        {
            forwardMessage(mymsg,0);
        }
        else if(hop_left == 0 && getIndex() < valid_num_Process)
        {
            delete mymsg;
        }
        else
        {
            delete mymsg;
            FatTreeMsg *newmsg = generateMessage(hop_left - 1);
            srand(time(0));
            int out_port = rand() % (6 - 1 + 1)  + 1 ; //[a,b] = rand() %(b-a+1) +a
            // selfMsgForwardGap = new cMessage("selfMsgForwardGap");
            // scheduleAt(simTime() + forward_gap[delay_index], selfMsgForwardGap);
            forwardMessage(newmsg,out_port);
        }
    }
    
}


//调用...计算路由端口
void Router::forwardMessage(FatTreeMsg *msg, int out_port_id)
{
    int k = out_port_id;
    char str1[20]="port_";
    char str2[20];
    sprintf(str2, "%d", k);
    strcat(str1,str2);
    strcat(str1,"$o");
    send(msg,str1);
}


void Router::finish()
{
    // This function is called by OMNeT++ at the end of the simulation.
    //EV << "Sent:     " << numSent << endl;
    //EV << "Received: " << numReceived << endl;
    //EV << "Hop count, min:    " << hopCountStats.getMin() << endl;
    //EV << "Hop count, max:    " << hopCountStats.getMax() << endl;
    //EV << "Hop count, mean:   " << hopCountStats.getMean() << endl;
    //EV << "Hop count, stddev: " << hopCountStats.getStddev() << endl;

    //recordScalar("#sent", numSent);
    //recordScalar("#received", numReceived);

    //hopCountStats.recordAs("hop count");

}




