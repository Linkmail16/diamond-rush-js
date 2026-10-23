#include "game.h"

Ref<Midlet> Midlet::init() {
	Midlet::version = this->getAppProperty(u"MIDlet-Version"_j)->getBytes();
	this->game = jnew<Game>()->init(this);
	return this;
}

void Midlet::startApp() {
	if (this->display == nullptr) {
		this->display = Display::getDisplay(this);
	}
	this->display->setCurrent(this->game);
	this->game->resumeGame();
}

void Midlet::pauseApp() {
	this->game->pauseGame();
	this->notifyPaused();
}

void Midlet::destroyApp(bool unconditional) {
	this->notifyDestroyed();
}

void Midlet::exitGame() {
	Ref<Object> s0;
	Game::requestQuit();
	this->game->sound->release();
	this->releaseReferences();
	try {
		this->destroyApp(1);
	} catch (JavaException& ex) {
		if (ex.isa(u"javax/microedition/midlet/MIDletStateChangeException")) {
			s0 = ex.ex;
			return;
		}
		else throw;
	}
}

void Midlet::releaseReferences() {
	this->game = nullptr;
	this->display = nullptr;
	JSystem::gc();
}

void Midlet::clinit() {
	Midlet::version = nullptr;
}

