/*
 * fat_tree.h
 *
 *  Created on: 2017��1��16��
 *      Author: Vincent
 *
 */
// The fat_tree_simple use the parameter of Dawn-5000
// The Dawn-5000 has following parameter:
// 16-port switch, 3 layer fat-tree, total 1024 compute nodes
#ifndef FAT_TREE_H_
#define FAT_TREE_H_

//�������˲���
#define PortNum 16
#define LevelNum 3
#define ProcessorNum 1024
#define SwitchNum 320
//#define LinkNum 6144
#define SwTop 64
#define SwLower 256
#define SwLowEach 128

//#define VC 4 //virtual channel
//#define BufferDepth 4 //virtual channel buffer depth, ���ڵ���2
#define RouterOverhead 12 //��λΪCLK_CYCLE, ���ݴ�����˿ڻ��浽����˿ڻ���
#define RouterForwardGap 2 //��λΪCLK_CYCLE�� ���ݴ�·�������ⷢ��ʱ����������
#define ProcessorForwardGap 1//��λΪCLK_CYCLE��processor���ⷢ�����ݼ����ע�������ݲ�����������֣����ݲ������ȷ���buffer�У����������Ǵ�buffer�ж�ȡ

//#define FlitWidth 256
#define ProcessorBufferDepth 10 //processor��buffer�ĳ���
#define RouterBufferDepth 50 //router�����������������

//ʱ����ز���
#define FREQ 312.5e6  //ʱ�����ڣ���λhz
#define CLK_CYCLE 1/FREQ //ʱ������
#define Sim_Start_Time 1 //1s ��ʼ����
#define TimeScale 0.1 //���ģ����ڲ��ɷֲ��������Ʒֲ�����lambda=10����ʾ1s��10��flit���õ���ʱ��������TimeScale��roundȡ��


//Spatial Distribution
#define UNIFORM //�ռ���ȷֲ�

//Time Distribution
#define POISSON_DIST //���ò��ɷֲ�

//�����ƺͲ��ɷֲ���ȡֵ��ΧС��10����λʱ��Ϊ1s����TimeScale����л��㣬������ʱ������

//Poisson�ֲ�����
#define LAMBDA 7 //���ɷֲ������ڲ���ʱ������ָ���ֲ���lambda����ʾ��λʱ����(1s)�����֡�����䵹��Ϊʱ������ƽ��ֵ, ����lambda��ʾע����(0,10]
#define UniformInjectionRate 0.3 //����ʱ����`

//
#define Verbose 1
#define VERBOSE_DEBUG_MESSAGES 1
#define VERBOSE_DETAIL_DEBUG_MESSAGES 2



#endif /* FAT_TREE_H_ */
