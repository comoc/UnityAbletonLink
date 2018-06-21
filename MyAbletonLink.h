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

#ifndef MyAbletonLink_h
#define MyAbletonLink_h

#if defined(_MSC_VER)
#   if _MSC_VER < 1800 
#       error This project needs atleast Visual Studio 2013
#   endif
#elif __cplusplus<201103L
#error C++11 features are required to compile this source code.
#endif

#if defined(__APPLE__)
#define LINK_PLATFORM_MACOSX 1
#elif defined(_WIN32)
#define LINK_PLATFORM_WINDOWS 1
#elif defined(__linux__)
#define LINK_PLATFORM_LINUX 1
#else
#error This platform is not supported.
#endif

#ifdef _WIN32
#define LINKHUT_AUDIO_PLATFORM_ASIO 1
#endif
#include "ableton/Link.hpp"

#include <algorithm>
#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(WINAPI_FAMILY) || defined(__CYGWIN32__)
#define UNITY_INTERFACE_EXPORT __declspec(dllexport)
#define UNITY_INTERFACE_API __stdcall
#else
#define UNITY_INTERFACE_EXPORT
#define UNITY_INTERFACE_API
#endif

//#ifdef __cplusplus
//extern "C" {
//#endif
//    using numPeersCallback = void(UNITY_INTERFACE_API *)(int);
//    using tempoCallback = void(UNITY_INTERFACE_API *)(double);
//#ifdef __cplusplus
//}
//#endif

class MyAbletonLink {
public:
    struct Status
    {
        double beat;
        double phase;
        double tempo;
        double quantam;
        double time;
        int numPeers;
        Status() : beat(0.0), phase(0.0), tempo(0.0), quantam(0.0), time(0.0), numPeers(0) {}
    };
    MyAbletonLink();
    ~MyAbletonLink();
    
    MyAbletonLink(const MyAbletonLink&) = delete;
    MyAbletonLink& operator=(const ableton::Link&) = delete;
    MyAbletonLink(MyAbletonLink&&) = delete;
    MyAbletonLink& operator=(MyAbletonLink&&) = delete;
    
    void setup(double bpm);
    
    void setTempo(double bpm);
    double tempo();
    
    void setQuantum(double quantum);
    double quantum();
    
    void forceBeatAtTime(double beat);
    void requestBeatAtTime(double beat);
    
    void enable(bool bEnable);
    bool isEnabled() const;

    std::size_t numPeers();
    
    Status update();
    
//    void setNumPeersCallback(numPeersCallback cb);
//    void setTempoCallback(tempoCallback cb);
private:
    ableton::Link* link_;
    double quantum_;

	bool isNumPeersChanged_;
	int numPeers_;

	bool isTempoChanged_;
	double tempo_;

//    numPeersCallback npc;
//    tempoCallback tc;
};


#endif /* MyAbletonLink_h */
