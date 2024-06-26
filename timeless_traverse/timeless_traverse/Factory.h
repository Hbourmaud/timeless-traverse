﻿#pragma once

#include <functional>
#include <typeinfo>
#include <unordered_map>

#include "Managers/EntityManager.h"

/**
 * Very simple implementation of factory system
 */
template<typename Base>
class Factory {
public:
    using CreatorFunction = std::function<Base*()>;

    template<typename Derived>
    void Register() {
        creators[&typeid(Derived)] = []() -> Base* { return new Derived(); };
    }

    Base* Create(const std::type_info& classType) {
        auto it = creators.find(&classType);
        if (it != creators.end()) {
            return EntityManager::GetInstance().CreateEntity(it->second());
        }
        return nullptr;
    }

private:
    std::unordered_map<const std::type_info*, CreatorFunction> creators;
};
