cmake_minimum_required(VERSION 3.23)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Players)

add_executable(ex4
        Players/Healer.cpp
        Players/Healer.h
        Players/Ninja.cpp
        Players/Ninja.h
        Players/Player.cpp
        Players/Player.h
        Players/Warrior.cpp
        Players/Warrior.h
        Exception.h
        Mtmchkin.h
        Mtmchkin.cpp
        helper.cpp
        helper.h
        test.cpp
        utilities.cpp
        utilities.h
        Cards/Card.h
        Cards/Card.cpp
        Cards/BattleCard.h
        Cards/BattleCard.cpp
        Cards/Gremlin.h
        Cards/Gremlin.cpp
        Cards/Witch.h
        Cards/Witch.cpp
        Cards/Dragon.h
        Cards/Dragon.cpp
        Cards/Mana.cpp
        Cards/Mana.h
        Cards/Merchant.h
        Cards/Merchant.cpp
        Cards/Treasure.cpp
        Cards/Treasure.h
        Cards/Well.h
        Cards/Well.cpp
        Cards/Barfight.cpp
        Cards/Barfight.h





        )
