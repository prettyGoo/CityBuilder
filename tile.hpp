#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "animation_handler.hpp"


enum class TileType { VOID, GRASS, FOREST, WATER, RESIDENTIAL, COMMERCIAL, INDUSTRIAL, ROAD};

std::string tileTypeToStr(TileType type);

class Tile
{
    public:
    Animationhandler animHandler;
    TileType tileType;
    int tileVariant;

    sf::Sprite sprite;

    // Region IDs of the tile, tiles in the same region are connected
    int regions[1];

    int cost;

    // Current residents/employees
    double population;
    float production;
    float storedGoods;

    int maxPopPerLevel;
    int maxLevels;

    Tile() { }
    Tile(const unsigned int tileSize, const unsigned int height, sf::Texture& texture,
         const std::vector<Animation>& animations,
         const TileType tileType, const unsigned int cost, const unsigned int maxPopPerLevel,
         const unsigned int maxLevels)
    {
        this->tileType = tileType;
        this->tileVariant = 0;
        this->regions[0] = 0;

        this->cost = cost;
        this->population = 0;
        this->maxPopPerLevel = maxPopPerLevel;
        this->maxLevels = maxLevels;
        this->production = 0;
        this->storedGoods = 0;

        this->sprite.setOrigin(sf::Vector2f(0.0f, tileSize*(height-1)));
        this->sprite.setTexture(texture);
        this->animHandler.frameSize = sf::IntRect(0, 0, tileSize*2, tileSize*height);
        for(auto animation : animations)
        {
            this->animHandler.addAnim(animation);
        }
        this->animHandler.update(0.0f);
    }

    void draw(sf::RenderWindow& window, float dt);

    void update();

    std::string getCost()
    {
        return std::to_string(this->cost);
    }
};


#endif /* TILE_HPP */
