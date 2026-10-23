#include "game.h"

Ref<Rnd> Rnd::init() {
	return this;
}

int32_t Rnd::nextInRange(int32_t min, int32_t max) {
	return min + irem(JMath::abs(Rnd::random->nextInt()), max - min);
}

void Rnd::clinit() {
	Rnd::random = jnew<Random>(JSystem::currentTimeMillis());
}

