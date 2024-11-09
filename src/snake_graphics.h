/****************************************************************************************
 * Copyright (c) 2024 convexwf
 * All rights reserved.
 *
 * Project: snake-godot
 * File: snake_graphics.h
 * Email: convexwf@gmail.com
 * Created: 2024-11-10
 * Last modified: 2024-11-10
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Description: TODO
 ****************************************************************************************/

#ifndef SNAKE_GRAPHICS_H
#define SNAKE_GRAPHICS_H

#include <godot_cpp/godot.hpp>
#include <godot_cpp/core/defs.hpp>
#include "godot_cpp/classes/control.hpp"
#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/classes/tile_map.hpp"
#include "godot_cpp/classes/tile_set.hpp"
#include "godot_cpp/classes/viewport.hpp"
#include "godot_cpp/core/binder_common.hpp"
#include "godot_cpp/variant/variant.hpp"
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/marker2d.hpp>
#include <godot_cpp/classes/label.hpp>
#include <memory>

namespace godot {

class DoublyLinkedListNode {
    DoublyLinkedListNode *prev;
    DoublyLinkedListNode *next;
    Vector2 position;

    DoublyLinkedListNode() : prev(nullptr), next(nullptr), position(Vector2()) {
    }

    explicit DoublyLinkedListNode(const Vector2 &position)
        : prev(nullptr), next(nullptr), position(position) {
    }
};

class SnakeGraphics : public Node2D {
    GODOT_CLASS(SnakeGraphics, Node2D)

protected:
    static void _bind_methods();

public:
    void _draw();

private:
    std::unique_ptr<DoublyLinkedListNode> snake_head_;
    std::unique_ptr<DoublyLinkedListNode> snake_tail_;

    void _addSnakeHeadNode(const Vector2 &position);

    void _addSnakeTailNode(const Vector2 &position);
}

} // namespace godot

#endif
