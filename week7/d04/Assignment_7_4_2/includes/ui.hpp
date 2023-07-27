#ifndef UI_HPP
#define UI_HPP

#include <algorithm>
#include <string>
#include <vector>
#include <memory>
#include <iostream>

struct Position
{
    int x;
    int y;
    friend std::ostream& operator<<(std::ostream& os, const Position& pos);
};

std::ostream& operator<<(std::ostream& os, const Position& pos)
{
    os << "x: " << pos.x << " | y: " << pos.y;
    return os;
}

struct Color
{
    int r;
    int g;
    int b;
    double a;
    friend std::ostream& operator<<(std::ostream& os, const Color& col);
};

std::ostream& operator<<(std::ostream& os, const Color& color)
{
    os << "rgba(" << color.r << ',' << color.g << ',' << color.b << ',' << color.a << ")";
    return os;
}

struct Border
{
    int         width;
    Color       color;
    std::string style;
};

struct Label
{
    std::string text;
    int         font_size;
    std::string font;
};

class Widget
{
    public:
        virtual void on_click() {}
        virtual void on_focus() {}
        virtual void on_hover() {}
        virtual void move(Position pos) {}
        virtual Position get_position() const { return {0,0}; }
        virtual std::vector<std::string>& get_children() = 0;
        virtual void remove_child(std::string child) = 0;
        virtual void add_child(std::string child) = 0;
        virtual void print_children() const = 0;

        virtual ~Widget() = default;
        
        std::string cursor {"default"};
    private:

    protected:
        Position position {0, 0};
};

class Button : public Widget
{
    public:
        void on_click() override {
            color = {195, 195, 195, 1};
        }
        void on_hover() override {
            color = {225, 225, 225, 1};
            cursor = "pointer";
        }
        void on_focus() override {
            border.color = {0, 180, 255, 1};
        }
        std::vector<std::string>& get_children() override
        {
            return children;
        }
        void remove_child(std::string child) override
        {
            children.erase(std::find(children.begin(), children.end(), child));
        }
        void add_child(std::string child) override 
        {
            children.push_back(child);
        }
        void print_children() const override
        {
            std::cout << "children: \n";
            for (const auto& child : children)
            {
                std::cout << '\t' << child << '\n';
            }
        }
        Position get_position() const override
        {
            return position;
        }
        void move(Position pos) override
        {
            position = pos;
        }
        virtual ~Button() = default;

        Color color {250, 250, 250, 1};
        Border border {1, {0, 0, 0, 1}, "solid"};
        Label label {"Button", 12, "Sans-serif"};

    private:
        std::vector<std::string> children {"color", "border", "label"};
        
};

#endif
