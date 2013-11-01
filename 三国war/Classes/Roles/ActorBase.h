#ifndef _ACTOR_BASE_H_
#define _ACTOR_BASE_H_

#include "cocos2d.h"
using namespace cocos2d;

#include "ActorData.h"

class ActorBase : public CCNode
{
public :
//	ActorBase(ActorData* data);
	~ActorBase();
    CCSprite *_sprite;
    bool initWithActorData(ActorData* data);
    static ActorBase* create(ActorData* data);
    CC_SYNTHESIZE_RETAIN(ActorData*, mActorData, ActorData);
    CC_SYNTHESIZE(ActorDir, mActorDir, ActorDir);


	CCAnimate* _action_attack;
	CCAnimate* _action_attack_flip;
	CCAnimate* _action_run;
	CCAnimate* _action_run_flip;
	CCAnimate* _action_stand;
	CCAnimate* _action_stand_flip;
	CCAnimate* _action_dead;
	CCAnimate* _action_dead_flip;

	CCAction* _currentAnimateAction;

	void StateToRun();
	void StateToAttack();
	void StateToDead();
	void StateToStand();
    void actorLogic();
    static void sortActors(CCArray* array);
private :
    CC_SYNTHESIZE(float, _speed, speed);
    CC_SYNTHESIZE(int, _blood, blood);
    CC_SYNTHESIZE(int, _damage, damage);
    CC_SYNTHESIZE(int, _experience, experience);
    
    CC_SYNTHESIZE_RETAIN(ActorBase *, _target, target);
    static int less(const CCObject* obj0, const CCObject* obj1);
	void currentAnimateActionStop();
	void RunAnimateAction_RepeatForever(CCAnimate* action);
};

#endif