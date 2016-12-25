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

#if __cplusplus<201103L
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

#include "Link.hpp"

#include <algorithm>
#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

class MyAbletonLink {
public:
    struct Status
    {
        double beat;
        double phase;
        Status() : beat(0.0), phase(0.0){}
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
    
    bool isEnabled() const;
    void enable(bool bEnable);
    
    std::size_t numPeers();
    
    Status update();
    
private:
    ableton::Link* link;
    double quantum_;
};


#endif /* MyAbletonLink_h */
