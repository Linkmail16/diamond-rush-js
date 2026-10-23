'use strict';

class Tables {
	static upgradeCosts = null;
	static worldUnlockRequirements = null;
	static medallionPieceOffsets = null;
	static worldMapCursorPositions = null;
	static worldMapNeighbors = null;

	static clinit() {
		let t1, t2, t3, t4, t5, t6, t7, t8, t9;
		t1 = new Int32Array(4);
		t1[0] = 150;
		t1[1] = 400;
		t1[2] = 1000;
		t1[3] = 3000;
		Tables.upgradeCosts = t1;
		t2 = new Int32Array(3);
		t2[0] = 0;
		t2[1] = 10;
		t2[2] = 25;
		Tables.worldUnlockRequirements = t2;
		t3 = new Int32Array(8);
		t3[0] = -24;
		t3[1] = -23;
		t3[2] = 24;
		t3[3] = -23;
		t3[4] = 0;
		t3[5] = 23;
		t3[6] = 24;
		t3[7] = 23;
		Tables.medallionPieceOffsets = t3;
		t4 = new Int32Array(8);
		t4[0] = -33;
		t4[1] = -54;
		t4[2] = 14;
		t4[3] = -54;
		t4[4] = -8;
		t4[5] = -8;
		t4[6] = 22;
		t4[7] = 2;
		Tables.worldMapCursorPositions = t4;
		t5 = J.newArray(4);
		t6 = new Int8Array(4);
		t6[0] = -1;
		t6[1] = -1;
		t6[2] = 0;
		t6[3] = -1;
		t5[0] = t6;
		t7 = new Int8Array(4);
		t7[0] = 1;
		t7[1] = -1;
		t7[2] = 3;
		t7[3] = -1;
		t5[1] = t7;
		t8 = new Int8Array(4);
		t8[0] = 2;
		t8[1] = 2;
		t8[2] = -1;
		t8[3] = -1;
		t5[2] = t8;
		t9 = new Int8Array(4);
		t9[0] = -1;
		t9[1] = 0;
		t9[2] = -1;
		t9[3] = 2;
		t5[3] = t9;
		Tables.worldMapNeighbors = t5;
	}

}
