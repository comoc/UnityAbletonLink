/* Copyright 2016, Akihiro Komori. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "MyAbletonLink.h"
#include <algorithm>
#include <cmath>

using namespace std;

MyAbletonLink::MyAbletonLink()
    : link_(nullptr),
    quantum_(4.0),
	isNumPeersChanged_(false),
	numPeers_(0),
	isTempoChanged_(false),
	tempo_(0.0)
//    , npc(nullptr), tc(nullptr)
{
}

MyAbletonLink::~MyAbletonLink(){
    if(link_ != nullptr){
        link_->enable(false);
        delete link_;
    }
}

void MyAbletonLink::setup(double tempo){
    if(link_ != nullptr){
        link_->enable(false);
        delete link_;
    }
    link_ = new ableton::Link(tempo);
    link_->setNumPeersCallback([this](std::size_t peers){
		isNumPeersChanged_ = true;
		numPeers_ = static_cast<int>(peers);
    });

    link_->setTempoCallback([this](const double bpm){
		isTempoChanged_ = true;
		tempo_ = bpm;
    });
    link_->enable(true);
}

void MyAbletonLink::setTempo(double bpm){
    if (link_ == nullptr){
        return;
    }
	auto state = link_->captureAppSessionState();
    const auto time = link_->clock().micros();
    state.setTempo(bpm, time);
	link_->commitAppSessionState(state);
}

double MyAbletonLink::tempo(){
    if(link_ == nullptr){
        return 0.0;
    }
    return link_->captureAppSessionState().tempo();
}

void MyAbletonLink::setQuantum(double quantum){
    this->quantum_ = fmin(fmax(quantum, 2.0), 16.0);
}

double MyAbletonLink::quantum(){
    return quantum_;
}

void MyAbletonLink::forceBeatAtTime(double beat) {
    if(link_ == nullptr){
        return;
    }
    auto state = link_->captureAppSessionState();
    const auto time = link_->clock().micros();
    state.forceBeatAtTime(beat, time, quantum_);
    link_->commitAppSessionState(state);
}

void MyAbletonLink::requestBeatAtTime(double beat) {
    if(link_ == nullptr){
        return;
    }
    auto state = link_->captureAppSessionState();
    const auto time = link_->clock().micros();
    state.requestBeatAtTime(beat, time, quantum_);
    link_->commitAppSessionState(state);
}

void MyAbletonLink::enable(bool bEnable){
    if(link_ == nullptr){
        return;
    }
    link_->enable(bEnable);
}

bool MyAbletonLink::isEnabled() const{
    if(link_ == nullptr){
        return false;
    }
    return link_->isEnabled();
}

std::size_t MyAbletonLink::numPeers(){
    if(link_ == nullptr){
        return 0;
    }
    return link_->numPeers();
}

MyAbletonLink::Status MyAbletonLink::update(){
    Status status;
    if(link_ == nullptr){
        return status;
    }
    
    auto state = link_->captureAppSessionState();
    const auto time = link_->clock().micros();
    
    status.beat  = state.beatAtTime(time, quantum_);
    status.phase = state.phaseAtTime(time, quantum_);
    status.quantam = quantum_;
    status.tempo = state.tempo();
    status.time = std::chrono::duration_cast<std::chrono::milliseconds>(time).count();
    status.numPeers = static_cast<int>(link_->numPeers());
    
//    if (isNumPeersChanged && npc != nullptr) {
//        isNumPeersChanged = false;
//        npc(static_cast<int>(numPeers_));
//    }
//    if (isTempoChanged && tc != nullptr) {
//        isTempoChanged = false;
//        tc(static_cast<double>(tempo_));
//    }
    return status;
}

//void MyAbletonLink::setNumPeersCallback(numPeersCallback cb) {
//    npc = cb;
//}
//
//void MyAbletonLink::setTempoCallback(tempoCallback cb) {
//    tc = cb;
//}
