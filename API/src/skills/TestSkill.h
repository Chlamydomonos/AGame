#ifndef SKILLS_TEST_SKILL_H
#define SKILLS_TEST_SKILL_H

#include "../unit/Skill.h"

class TestSkill : public Skill
{
public:
	TestSkill();

	// ͨ�� Skill �̳�
	virtual void use(ServerUnit *from, ServerTile *target) override;
};

#endif // !SKILLS_TEST_H
