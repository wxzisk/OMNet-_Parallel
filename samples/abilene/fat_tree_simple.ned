simple Router
{
    parameters:
    gates:
        inout port_0;
        inout port_1;
        inout port_2;
        inout port_3;
        inout port_4;
}
simple Processor
{
    parameters:
    gates:
        inout port;
}
network Abilene
{
    types:
        channel Channel_1 extends ned.DatarateChannel
        {
            delay = 10us;
            datarate = 100Gbps;
        }
        channel Channel_2 extends ned.DatarateChannel
        {
            delay = 10us;
            datarate = 100Gbps;
        }
    submodules:
        // Router_1: 1
        // Router_2: 3 8 9 11 12
        // Router_3: 4 5 6 7 10
        // Router_3: 2 
        router[12]: Router{}
        processor[30]: Processor{}
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

        router[0].port_1<--> Channel_1 <--> router[1].port_1;
        router[1].port_2<--> Channel_2 <--> router[5].port_1;
        router[1].port_3<--> Channel_1 <--> router[11].port_1;
        router[1].port_4<--> Channel_1 <--> router[4].port_1;
        router[2].port_1<--> Channel_1 <--> router[5].port_2;
        router[2].port_3<--> Channel_1 <--> router[8].port_1;
        router[3].port_1<--> Channel_1 <--> router[6].port_1;
        router[3].port_2<--> Channel_1 <--> router[9].port_1;
        router[3].port_3<--> Channel_1 <--> router[10].port_1;
        router[4].port_2<--> Channel_1 <--> router[6].port_2;
        router[4].port_3<--> Channel_1 <--> router[7].port_1;
        router[5].port_3<--> Channel_1 <--> router[6].port_3;
        router[7].port_2<--> Channel_1 <--> router[9].port_2;
        router[8].port_2<--> Channel_1 <--> router[11].port_2;
        router[9].port_3<--> Channel_1 <--> router[10].port_2;
        
        router[0].port_2<--> Channel_1 <--> processor[12].port;
        router[0].port_3<--> Channel_1 <--> processor[13].port;
        router[0].port_4<--> Channel_1 <--> processor[14].port;
        router[2].port_4<--> Channel_1 <--> processor[15].port;
        router[3].port_4<--> Channel_1 <--> processor[16].port;
        router[4].port_4<--> Channel_1 <--> processor[17].port;
        router[5].port_4<--> Channel_1 <--> processor[18].port;
        router[6].port_4<--> Channel_1 <--> processor[19].port;
        router[7].port_3<--> Channel_1 <--> processor[20].port;
        router[7].port_4<--> Channel_1 <--> processor[21].port;
        router[8].port_3<--> Channel_1 <--> processor[22].port;
        router[8].port_4<--> Channel_1 <--> processor[23].port;
        router[9].port_4<--> Channel_1 <--> processor[24].port;
        router[10].port_3<--> Channel_1 <--> processor[25].port;
        router[10].port_4<--> Channel_1 <--> processor[26].port;
        router[11].port_3<--> Channel_1 <--> processor[27].port;
        router[11].port_4<--> Channel_1 <--> processor[28].port;
        router[2].port_2<--> Channel_1 <--> processor[29].port;
}
