#ifndef PLAYER_H
#define PLAYER_H

#include <string.h>
#include <time.h>
#include <stdint.h>
#include <Typedef.h>
#include "BasePlayer.h"

#define BETNUM		5
#define  GAME_END_NORMAL       0
#define  GAME_END_DISCONNECT   1
#define  GAME_END_DISCARD     2 

class Player
{
	public:
		Player(){};
		virtual ~Player(){};
		void init();
	//内置函数
	public:
		inline bool isLogout() {return m_nStatus == STATUS_PLAYER_LOGOUT;};
		inline void setActiveTime(time_t t){active_time = t;}
        inline time_t getActiveTime(){return active_time;}
		inline void setEnterTime(time_t t){enter_time = t;}
		inline time_t getEnterTime(){return enter_time;}
	//行为函数
	public:
		void leave(bool isSendToUser = true);
		void enter();
		void reset();
		bool notBetCoin();
		void login();

	public:
		int id;
		char name[64];
		char json[1024];
		char headlink[128];
		short m_nHallid;
		short m_nStatus;
		short m_nTabIndex;
		int tax;				//玩家上交的税费
		int64_t m_lMoney;
		int64_t m_lWinScore;						//最终输赢金币
		int64_t m_lReturnScore;						//自己下注的金币
		int64_t m_lLoseScore;						//输的金币
		int64_t m_lResultArray[BETNUM];
		int64_t m_lTempScore;						//暂时
		int tid;
		short source;
		short m_nSeatID;
		int m_nWin;
		int m_nLose;
		int m_nRunAway;
		int m_nTie;
		BYTE m_bisCall;								//这盘是否抢了庄
		int64_t m_lBetArray[BETNUM];
		bool isonline;
		int m_nRoll;
		int m_nExp;
		bool m_bhasOpen;
		//是否在上庄列表
		bool isbankerlist;
		bool isCanlcebanker;

		int m_nChatCostCount;						//聊天花费金币
		int64_t m_lRewardCoin;						//中奖金币数额
		
		int64_t m_lMaxWinMoney;
		int64_t m_lMaxCardValue;

		int m_nLastBetTime;
		int m_seatid;

	public:
		short pid;
		short cid;
		short sid;
	private:
		time_t active_time;							//客户端最近活跃时间
		time_t enter_time;							//进入游戏的时间
		time_t replay_time;							//游戏等待时间，新一盘游戏开始时计时，用于机器人判断当前等待时间
		time_t timeout_time;						//游戏给他设置超时时间的时刻

};
#endif
