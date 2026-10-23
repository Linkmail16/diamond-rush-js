'use strict';

class Midlet extends MIDlet {
	static version = null;
	game = null;
	display = null;

	init() {
		Midlet.version = J.getBytes(this.getAppProperty("MIDlet-Version"));
		this.game = new Game().init(this);
		return this;
	}

	startApp() {
		if (this.display === null) {
			this.display = Display.getDisplay(this);
		}
		this.display.setCurrent(this.game);
		this.game.resumeGame();
	}

	pauseApp() {
		this.game.pauseGame();
		this.notifyPaused();
	}

	destroyApp(unconditional) {
		this.notifyDestroyed();
	}

	exitGame() {
		let s0;
		Game.requestQuit();
		this.game.sound.release();
		this.releaseReferences();
		try {
			this.destroyApp(1);
		} catch (ex) {
			ex = J.exc(ex);
			if (J.isa(ex, "javax/microedition/midlet/MIDletStateChangeException")) {
				s0 = ex;
				return;
			}
			else throw ex;
		}
	}

	releaseReferences() {
		this.game = null;
		this.display = null;
		JSystem.gc();
	}

	static clinit() {
		Midlet.version = null;
	}

}
