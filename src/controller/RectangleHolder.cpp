#include "RectangleHolder.h"
#include "Macros.h"

//================== public functions ======================
//==========================================================
const sf::RectangleShape& RectangleHolder::getSprite() const
{
	if (m_spr_off.getTexture() == nullptr)
		return m_spr_on;
	return m_is_on ? m_spr_on : m_spr_off;
}

//==========================================================
void RectangleHolder::rotate(const int dir)
{
	if (dir) {
		m_spr_on.rotate(TWO_HUND_SEVENY_DEGREES);
		m_spr_off.rotate(TWO_HUND_SEVENY_DEGREES);
	}
	else {
		m_spr_on.rotate(NINETY_DEGREES);
		m_spr_off.rotate(NINETY_DEGREES);
	}
}
