#pragma once
#include "SFML/Graphics.hpp"
#include "Objects/Sprite_object.hpp"

struct Rectangle
{
        virtual float x() const noexcept = 0;
        virtual float y() const noexcept = 0;
        virtual float width() const noexcept = 0;
        virtual float height() const noexcept = 0;
        virtual float left() const noexcept = 0;
        virtual float right() const noexcept = 0;
        virtual float top() const noexcept = 0;
        virtual float bottom() const noexcept = 0;
};

bool operator==(const Rectangle &a, const Rectangle &b);

bool operator!=(const Rectangle &a, const Rectangle &b);

struct Circle
{
        virtual float x() const noexcept = 0;
        virtual float y() const noexcept = 0;
        virtual float radius() const noexcept = 0;
        virtual float left() const noexcept = 0;
        virtual float right() const noexcept = 0;
        virtual float top() const noexcept = 0;
        virtual float bottom() const noexcept = 0;
};

bool operator==(const Circle &a, const Circle &b);

bool operator!=(const Circle &a, const Circle &b);
