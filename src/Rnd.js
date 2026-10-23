'use strict';

class Rnd {
	static random = null;

	init() {
		return this;
	}

	static nextInRange(min, max) {
		return min + J.irem(Math.abs(Rnd.random.nextInt()) | 0, max - min | 0) | 0;
	}

	static clinit() {
		Rnd.random = new Random(JSystem.currentTimeMillis());
	}

}
