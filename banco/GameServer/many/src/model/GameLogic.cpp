
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "GameLogic.h"

//////////////////////////////////////////////////////////////////////////

//扑克数据
const BYTE CGameLogic::m_cbCardListData[52*8]=
{
	0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,	//方块 A - K
	0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,	//梅花 A - K
	0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,	//红桃 A - K
	0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,	//黑桃 A - K

	0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,	//方块 A - K
	0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,	//梅花 A - K
	0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,	//红桃 A - K
	0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,	//黑桃 A - K

	0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,	//方块 A - K
	0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,	//梅花 A - K
	0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,	//红桃 A - K
	0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,	//黑桃 A - K

	0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,	//方块 A - K
	0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,	//梅花 A - K
	0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,	//红桃 A - K
	0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,	//黑桃 A - K

	0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,	//方块 A - K
	0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,	//梅花 A - K
	0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,	//红桃 A - K
	0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,	//黑桃 A - K

	0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,	//方块 A - K
	0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,	//梅花 A - K
	0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,	//红桃 A - K
	0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,	//黑桃 A - K

	0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,	//方块 A - K
	0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,	//梅花 A - K
	0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,	//红桃 A - K
	0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,	//黑桃 A - K

	0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,	//方块 A - K
	0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,	//梅花 A - K
	0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,	//红桃 A - K
	0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,	//黑桃 A - K
};

//////////////////////////////////////////////////////////////////////////

//构造函数
CGameLogic::CGameLogic()
{
	
}

//析构函数
CGameLogic::~CGameLogic()
{
}

std::string CGameLogic::GetCardColorName(BYTE card)
{
    BYTE color = 0xF0 & card;
    if (color == 0x00)
        return "方块";
    else if (color == 0x10)
        return "梅花";
    else if (color == 0x20)
        return "红桃";
    else if (color == 0x30)
        return "黑桃";
    else
        return "";
}

std::string CGameLogic::GetCardValueName(BYTE card)
{
    BYTE value = 0x0F & card;
    if (value == 1)
    {
        return "A";
    }
    else if (value > 1 && value < 11)
    {
        char card_name[8] = { 0 };
        sprintf(card_name , "%d" , value);
        return card_name;
    }
    else if (value == 11)
    {
        return "J";
    }
    else if (value == 12)
    {
        return "Q";
    }
    else if (value == 13)
    {
        return "K";
    }
    else
    {
        return "";
    }
}

std::string CGameLogic::getCardInfo(BYTE card)
{
    return GetCardColorName(card) + GetCardValueName(card);
}


////混乱扑克
//void CGameLogic::RandCardList(BYTE cbCardBuffer[], BYTE cbBufferCount,LONGLONG dwUserID)
//{
//
//	srand((LONGLONG)(GetTickCount()/66+dwUserID));
//	//混乱准备
//	BYTE cbCardData[CountArray(m_cbCardListData)];
//	CopyMemory(cbCardData,m_cbCardListData,sizeof(m_cbCardListData));
//
//	//混乱扑克
//	BYTE cbRandCount=0,cbPosition=0;
//	do
//	{
//		cbPosition=rand()%(CountArray(cbCardData)-cbRandCount);
//		cbCardBuffer[cbRandCount++]=cbCardData[cbPosition];
//		cbCardData[cbPosition]=cbCardData[CountArray(cbCardData)-cbRandCount];
//	} while (cbRandCount<cbBufferCount);
//
//	return;
//}


//混乱扑克
void CGameLogic::RandCardList(BYTE cbCardBuffer[], BYTE cbBufferCount)
{
    //混乱准备
    BYTE bCardData[sizeof(m_cbCardListData)];
    CopyMemory(bCardData,m_cbCardListData,sizeof(m_cbCardListData));

    // 洗牌
    int i = sizeof(m_cbCardListData), j;
    BYTE temp;
    while (--i)
    {
        j = rand() % (i + 1);
        temp = bCardData[i];
        bCardData[i] = bCardData[j];
        bCardData[j] = temp;
    }

    // 抽牌 发牌
    BYTE bRandCount=0,bPosition=0;
    do
    {
        bPosition=rand()%(CountArray(bCardData)-bRandCount);
        cbCardBuffer[bRandCount++]=bCardData[bPosition];
        bCardData[bPosition]=bCardData[CountArray(bCardData)-bRandCount];
    } while (bRandCount<cbBufferCount);
}


BYTE* CGameLogic::Shuffle(size_t& count, int randSeed)
{
    srand(randSeed);
	static BYTE bCardData[sizeof(m_cbCardListData)] = { 0 };
	CopyMemory(bCardData, m_cbCardListData, sizeof(m_cbCardListData));
	int i = sizeof(m_cbCardListData), j;
	count = sizeof(m_cbCardListData);
	BYTE temp;

	while (--i) 
	{
		j = rand() % (i + 1);
		temp = bCardData[i];
		bCardData[i] = bCardData[j];
		bCardData[j] = temp;
	}
	return bCardData;
}


//获取牌点
BYTE CGameLogic::GetCardPip(BYTE cbCardData)
{
	//计算牌点
	BYTE cbCardValue=GetCardValue(cbCardData);
	BYTE cbPipCount=(cbCardValue>=10)?0:cbCardValue;

	return cbPipCount;
}

//获取牌点
BYTE CGameLogic::GetCardListPip(const BYTE cbCardData[], BYTE cbCardCount)
{
	//变量定义
	BYTE cbPipCount=0;

	//获取牌点
	for (BYTE i=0;i<cbCardCount;i++)
	{
		cbPipCount=(GetCardPip(cbCardData[i])+cbPipCount)%10;
	}

	return cbPipCount;
}

//////////////////////////////////////////////////////////////////////////
