#include "Tank.h"
#include "Game.h"
#include "TankAction.h"
#include "BossTankAction.h"
#include "LogicEngine.h"
#include "RandomEngine.h"
#include "ResourceManager.h"

Tank* CreateTank(TANKSTYLE tankstyle, void * me, LogicSprite * super, TankData td, 
	int bcl, int bct, int bcw, int bch,
	int cl, int ct, int cw, int ch,
	double ori, void(*decide)(Tank* tis), void(*act)(int t, Tank* tis), void(*dead)(Tank* tis))
{
	Tank* t = (Tank*)malloc(sizeof(Tank));
	memset(t, 0, sizeof(Tank));
	t->m_tankStyle_ = tankstyle;
	t->m_extra_ = me;
	t->m_super_ = super;
	t->m_data_ = td;
	t->m_HP = td.m_HPmax_;
	t->m_srcBulletCollideL = bcl;
	t->m_srcBulletCollideT = bct;
	t->m_srcBulletCollideW = bcw;
	t->m_srcBulletCollideH = bch;
	t->m_srcCollideL = cl;
	t->m_srcCollideT = ct;
	t->m_srcCollideW = cw;
	t->m_srcCollideH = ch;
	t->m_bulletCollideL = bcl;
	t->m_bulletCollideT = bct;
	t->m_bulletCollideW = bcw;
	t->m_bulletCollideH = bch;
	t->m_collideL = cl;
	t->m_collideT = ct;
	t->m_collideW = cw;
	t->m_collideH = ch;
	t->m_orientation_ = ori;
	t->Decide = decide;
	t->Act = act;
	t->Dead = dead;
	t->m_valid_ = TRUE;
	return t;
}

BOOLean TryShoot(Tank * t)
{
	return BOOLean();
}

Tank * CreateStronghold(LogicSprite * ls)
{
	Tank* t = CreateTank(TANK_STRONGHOLD, NULL, ls, m_tankData_[TANK_STRONGHOLD],
		7, 25, 45, 38, 7, 25, 45, 38,
		0.0);
	return t;
}

Tank* CreatePlayerTank(LogicSprite* ls) {
	Tank* t = CreateTank(TANK_PLAYER, NULL, ls, m_tankData_[TANK_PLAYER],
		36, 36, 10, 10, 16, 18, 50, 44,
		V6_DRT_UP);
	t->m_noOrientation_ = TRUE;
	PlayerTank* pt = (PlayerTank*)malloc(sizeof(PlayerTank));
	memset(pt, 0, sizeof(PlayerTank));
	pt->m_palstance_ = 2 * V6_PI;
	t->m_extra_ = pt;
	return t;
}

Tank * CreateJunkTank(LogicSprite * ls)
{
	Tank* t = CreateTank(TANK_JUNK, NULL, ls, m_tankData_[TANK_JUNK],
		22, 18, 41, 41, 15, 13, 55, 56,
		0.0);
	t->Decide = TankJunkAI;
	t->Act = TankJunkAct;
	ChangeTankOrientation(t, double(NextRand() % 4) * V6_DRT_UP);
	return t;
}
Tank * CreateBigTank(LogicSprite * ls)
{
	Tank* t = CreateTank(TANK_BIG, NULL, ls, m_tankData_[TANK_BIG],
		11, 14, 57, 56, 11, 14, 57, 56,
		0.0);
	t->Decide = TankJunkAI;
	t->Act = TankBigAct;
	ChangeTankOrientation(t, double(NextRand() % 4) * V6_DRT_UP);
	return t;
}

Tank * CreatePrismTank(LogicSprite * ls)
{
	Tank* t = CreateTank(TANK_PRISM, NULL, ls, m_tankData_[TANK_PRISM],
		23, 23, 33, 33, 9, 9, 63, 63,
		0.0);
	t->Decide = TankPrismAI;
	t->Act = TankPrismAct;
	t->m_noOrientation_ = TRUE;
	ChangeTankOrientation(t, double(NextRand() % 4) * V6_DRT_UP);
	return t;
}

Tank * CreateFiveTank(LogicSprite * ls)
{
	Tank* t = CreateTank(TANK_FIVE, NULL, ls, m_tankData_[TANK_FIVE],
		9, 10, 35, 53, 4, 6, 69, 66,
		0.0);
	t->Decide = TankFiveAI;
	t->Act = TankFiveAct;
	ChangeTankOrientation(t, double(NextRand() % 4) * V6_DRT_UP);
	return t;
}

Tank * CreateQuickTank(LogicSprite * ls)
{
	Tank* t = CreateTank(TANK_QUICK, NULL, ls, m_tankData_[TANK_QUICK],
		10, 35, 61, 15, 10, 29, 61, 27,
		0.0);
	t->Decide = TankJunkAI;
	t->Act = TankQuickAct;
	ChangeTankOrientation(t, double(NextRand() % 4) * V6_DRT_UP);
	return t;
}

Tank * CreateSunTank(LogicSprite * ls)
{
	Tank* t = CreateTank(TANK_SUN, NULL, ls, m_tankData_[TANK_SUN],
		18, 18, 40, 42, 10, 9, 59, 59,
		0.0);
	t->Decide = TankFiveAI;
	t->Act = TankSunAct;
	t->m_noOrientation_ = TRUE;
	ChangeTankOrientation(t, double(NextRand() % 4) * V6_DRT_UP);
	return t;
}

Tank * CreateLanlingkingTank(LogicSprite * ls)
{
	Tank* t = CreateTank(TANK_LANLINGKING, NULL, ls, m_tankData_[TANK_LANLINGKING],
		23, 23, 33, 33, 9, 9, 63, 63,
		0.0);
	t->Decide = TankLanlingkingAI;
	t->Act = TankLanlingkingAct;
	LanlingkingTank* ex = (LanlingkingTank*)malloc(sizeof(LanlingkingTank));
	ex->m_contiousShootCountLeft_ = 0;
	t->m_extra_ = ex;
	ChangeTankOrientation(t, double(NextRand() % 4) * V6_DRT_UP);
	return t;
}

Tank * CreateAttackTank(LogicSprite * ls)
{
	Tank* t = CreateTank(TANK_ATTACK, NULL, ls, m_tankData_[TANK_ATTACK],
		19, 30, 43, 18, 15, 19, 49, 36,
		0.0);
	t->Decide = TankAttackAI;
	t->Act = TankAttackAct;
	AttackTank* ex = (AttackTank*)malloc(sizeof(AttackTank));
	if (NextRand() % 2) 
		ex->m_aim_ = m_playerTank_;
	else
		ex->m_aim_ = m_stronghold_;
	ex->m_tracking_ = NextRand() % 2;
	t->m_extra_ = ex;
	t->m_noOrientation_ = TRUE;
	ChangeTankOrientation(t, double(NextRand() % 4) * V6_DRT_UP);
	return t;
}

void ChangeTankOrientation(Tank * t, double ori)
{
	int i = ori / V6_DRT_UP;
	t->m_orientation_ = ori;
	if (!t->m_noOrientation_) {
		switch (i) {
		case 0:
			t->m_bulletCollideL = t->m_srcBulletCollideL;
			t->m_bulletCollideT = t->m_srcBulletCollideT;
			t->m_bulletCollideW = t->m_srcBulletCollideW;
			t->m_bulletCollideH = t->m_srcBulletCollideH;
			t->m_collideL = t->m_srcCollideL;
			t->m_collideT = t->m_srcCollideT;
			t->m_collideW = t->m_srcCollideW;
			t->m_collideH = t->m_srcCollideH;
			break;
		case 1:
			t->m_bulletCollideL = t->m_srcBulletCollideT;
			t->m_bulletCollideT = t->m_super_->m_w_ - t->m_srcBulletCollideL - t->m_srcBulletCollideW;
			t->m_bulletCollideW = t->m_srcBulletCollideH;
			t->m_bulletCollideH = t->m_srcBulletCollideW;
			t->m_collideL = t->m_srcCollideT;
			t->m_collideT = t->m_super_->m_w_ - t->m_srcCollideL - t->m_srcCollideW;
			t->m_collideW = t->m_srcCollideH;
			t->m_collideH = t->m_srcCollideW;
			break;
		case 2:
			t->m_bulletCollideL = t->m_super_->m_w_ - t->m_srcBulletCollideL - t->m_srcBulletCollideW;
			t->m_bulletCollideT = t->m_srcBulletCollideT;
			t->m_bulletCollideW = t->m_srcBulletCollideW;
			t->m_bulletCollideH = t->m_srcBulletCollideH;
			t->m_collideL = t->m_super_->m_w_ - t->m_srcCollideL - t->m_srcCollideW;
			t->m_collideT = t->m_srcCollideT;
			t->m_collideW = t->m_srcCollideW;
			t->m_collideH = t->m_srcCollideH;
			break;
		case 3:
			t->m_bulletCollideL = t->m_srcBulletCollideL;
			t->m_bulletCollideT = t->m_super_->m_w_ - t->m_srcBulletCollideT - t->m_srcBulletCollideH;
			t->m_bulletCollideW = t->m_srcBulletCollideH;
			t->m_bulletCollideH = t->m_srcBulletCollideW;
			t->m_collideL = t->m_srcCollideL;
			t->m_collideT = t->m_super_->m_w_ - t->m_srcCollideT - t->m_srcCollideH;
			t->m_collideW = t->m_srcCollideH;
			t->m_collideH = t->m_srcCollideW;
			break;
		}
	}
}
