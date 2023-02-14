simple Router
{
    parameters:
    gates:
        inout port_0;
        inout port_1;
        inout port_2;
        inout port_3;
        inout port_4;
        inout port_5;
        inout port_6;
}
simple Processor
{
    parameters:
    gates:
        inout port;
}
network Geanet
{
    types:
        channel Channel_1 extends ned.DatarateChannel
        {
            delay = 10us;
           datarate = 9.92Gbps;
        }
        channel Channel_2 extends ned.DatarateChannel
        {
            delay = 10us;
           datarate = 2.48Gbps;
        }
    submodules:
        router[23]: Router{}
        processor[89]: Processor{}
    connections:
        processor[0].port <--> Channel_1 <--> router[0].port_0;
        processor[1].port <--> Channel_1 <--> router[1].port_0;
        processor[2].port <--> Channel_1 <--> router[2].port_0;
        processor[3].port <--> Channel_1 <--> router[3].port_0;
        processor[4].port <--> Channel_1 <--> router[4].port_0;
        processor[5].port <--> Channel_1 <--> router[5].port_0;
        processor[6].port <--> Channel_1 <--> router[6].port_0;
        processor[7].port <--> Channel_1 <--> router[7].port_0;
        processor[8].port <--> Channel_1 <--> router[8].port_0;
        processor[9].port <--> Channel_1 <--> router[9].port_0;
        processor[10].port <--> Channel_1 <--> router[10].port_0;
        processor[11].port <--> Channel_1 <--> router[11].port_0;
        processor[12].port <--> Channel_1 <--> router[12].port_0;
        processor[13].port <--> Channel_1 <--> router[13].port_0;
        processor[14].port <--> Channel_1 <--> router[14].port_0;
        processor[15].port <--> Channel_1 <--> router[15].port_0;
        processor[16].port <--> Channel_1 <--> router[16].port_0;
        processor[17].port <--> Channel_1 <--> router[17].port_0;
        processor[18].port <--> Channel_1 <--> router[18].port_0;
        processor[19].port <--> Channel_1 <--> router[19].port_0;
        processor[20].port <--> Channel_1 <--> router[20].port_0;
        processor[21].port <--> Channel_1 <--> router[21].port_0;
        processor[22].port <--> Channel_1 <--> router[22].port_0;
        router[0].port_1<--> Channel_1 <--> router[2].port_1;
        router[0].port_2<--> Channel_1 <--> router[5].port_1;
        router[0].port_3<--> Channel_1 <--> router[9].port_1;
        router[0].port_4<--> Channel_2 <--> router[15].port_1;
        router[0].port_5<--> Channel_2 <--> router[20].port_1;
        router[1].port_1<--> Channel_2 <--> router[7].port_1;
        router[1].port_2<--> Channel_2 <--> router[11].port_1;
        router[1].port_3<--> Channel_2 <--> router[21].port_1;
        router[2].port_2<--> Channel_1 <--> router[7].port_2;
        router[2].port_3<--> Channel_1 <--> router[10].port_1;
        router[3].port_1<--> Channel_1 <--> router[4].port_1;
        router[3].port_2<--> Channel_2 <--> router[12].port_1;
        router[3].port_3<--> Channel_2 <--> router[16].port_1;
        router[4].port_2<--> Channel_2 <--> router[5].port_2;
        router[4].port_3<--> Channel_1 <--> router[7].port_3;
        router[4].port_4<--> Channel_1 <--> router[11].port_2;
        router[4].port_5<--> Channel_2 <--> router[19].port_1;
        router[5].port_3<--> Channel_2 <--> router[8].port_1;
        router[5].port_4<--> Channel_1 <--> router[10].port_2;
        router[5].port_5<--> Channel_1 <--> router[14].port_1;
        router[6].port_1<--> Channel_1 <--> router[7].port_4;
        router[6].port_2<--> Channel_1 <--> router[10].port_3;
        router[6].port_3<--> Channel_2 <--> router[13].port_1;
        router[7].port_5<--> Channel_1 <--> router[17].port_1;
        router[7].port_6<--> Channel_2 <--> router[21].port_2;
        router[8].port_2<--> Channel_2 <--> router[10].port_4;
        router[9].port_2<--> Channel_2 <--> router[16].port_2;
        router[9].port_3<--> Channel_2 <--> router[18].port_1;
        router[10].port_5<--> Channel_2 <--> router[22].port_1;
        router[11].port_3<--> Channel_1 <--> router[17].port_2;
        router[12].port_2<--> Channel_2 <--> router[22].port_2;
        router[12].port_3<--> Channel_1 <--> router[14].port_2;
        router[13].port_2<--> Channel_2 <--> router[16].port_3;
        router[14].port_3<--> Channel_1 <--> router[17].port_3;
        router[15].port_2<--> Channel_2 <--> router[18].port_2;
        router[17].port_4<--> Channel_2 <--> router[20].port_2;
        router[0].port_6<--> Channel_2 <--> processor[88].port;
        router[1].port_4<--> Channel_2 <--> processor[87].port;
        router[1].port_5<--> Channel_2 <--> processor[86].port;
        router[1].port_6<--> Channel_2 <--> processor[85].port;
        router[2].port_4<--> Channel_2 <--> processor[84].port;
        router[2].port_5<--> Channel_2 <--> processor[83].port;
        router[2].port_6<--> Channel_2 <--> processor[82].port;
        router[3].port_4<--> Channel_2 <--> processor[81].port;
        router[3].port_5<--> Channel_2 <--> processor[80].port;
        router[3].port_6<--> Channel_2 <--> processor[79].port;
        router[4].port_6<--> Channel_2 <--> processor[78].port;
        router[5].port_6<--> Channel_2 <--> processor[77].port;
        router[6].port_4<--> Channel_2 <--> processor[76].port;
        router[6].port_5<--> Channel_2 <--> processor[75].port;
        router[6].port_6<--> Channel_2 <--> processor[74].port;
        router[8].port_3<--> Channel_2 <--> processor[73].port;
        router[8].port_4<--> Channel_2 <--> processor[72].port;
        router[8].port_5<--> Channel_2 <--> processor[71].port;
        router[8].port_6<--> Channel_2 <--> processor[70].port;
        router[9].port_4<--> Channel_2 <--> processor[69].port;
        router[9].port_5<--> Channel_2 <--> processor[68].port;
        router[9].port_6<--> Channel_2 <--> processor[67].port;
        router[10].port_6<--> Channel_2 <--> processor[66].port;
        router[11].port_4<--> Channel_2 <--> processor[65].port;
        router[11].port_5<--> Channel_2 <--> processor[64].port;
        router[11].port_6<--> Channel_2 <--> processor[63].port;
        router[12].port_4<--> Channel_2 <--> processor[62].port;
        router[12].port_5<--> Channel_2 <--> processor[61].port;
        router[12].port_6<--> Channel_2 <--> processor[60].port;
        router[13].port_3<--> Channel_2 <--> processor[59].port;
        router[13].port_4<--> Channel_2 <--> processor[58].port;
        router[13].port_5<--> Channel_2 <--> processor[57].port;
        router[13].port_6<--> Channel_2 <--> processor[56].port;
        router[14].port_4<--> Channel_2 <--> processor[55].port;
        router[14].port_5<--> Channel_2 <--> processor[54].port;
        router[14].port_6<--> Channel_2 <--> processor[53].port;
        router[15].port_3<--> Channel_2 <--> processor[52].port;
        router[15].port_4<--> Channel_2 <--> processor[51].port;
        router[15].port_5<--> Channel_2 <--> processor[50].port;
        router[15].port_6<--> Channel_2 <--> processor[49].port;
        router[16].port_4<--> Channel_2 <--> processor[48].port;
        router[16].port_5<--> Channel_2 <--> processor[47].port;
        router[16].port_6<--> Channel_2 <--> processor[46].port;
        router[17].port_5<--> Channel_2 <--> processor[45].port;
        router[17].port_6<--> Channel_2 <--> processor[44].port;
        router[18].port_3<--> Channel_2 <--> processor[43].port;
        router[18].port_4<--> Channel_2 <--> processor[42].port;
        router[18].port_5<--> Channel_2 <--> processor[41].port;
        router[18].port_6<--> Channel_2 <--> processor[40].port;
        router[19].port_2<--> Channel_2 <--> processor[39].port;
        router[19].port_3<--> Channel_2 <--> processor[38].port;
        router[19].port_4<--> Channel_2 <--> processor[37].port;
        router[19].port_5<--> Channel_2 <--> processor[36].port;
        router[19].port_6<--> Channel_2 <--> processor[35].port;
        router[20].port_3<--> Channel_2 <--> processor[34].port;
        router[20].port_4<--> Channel_2 <--> processor[33].port;
        router[20].port_5<--> Channel_2 <--> processor[32].port;
        router[20].port_6<--> Channel_2 <--> processor[31].port;
        router[21].port_3<--> Channel_2 <--> processor[30].port;
        router[21].port_4<--> Channel_2 <--> processor[29].port;
        router[21].port_5<--> Channel_2 <--> processor[28].port;
        router[21].port_6<--> Channel_2 <--> processor[27].port;
        router[22].port_3<--> Channel_2 <--> processor[26].port;
        router[22].port_4<--> Channel_2 <--> processor[25].port;
        router[22].port_5<--> Channel_2 <--> processor[24].port;
        router[22].port_6<--> Channel_2 <--> processor[23].port;
}
