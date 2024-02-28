/**
 * @file entity.h
 *
 * @brief Header file of the Entity class
 *
 * This file is part of RLFWB, a RayLib Framework for Bubbleshooter
 *
 * - Copyright 2024 Douwe westerdijk <westerdijk@protonmail.com>
 *
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>
#include <iostream>
#include <assert.h>
#include <vector>

#define BACKGROUND_COLOR (BLACK)

class Entity
{
public:
  /// @brief Constructor of Entity
  Entity();
  /// @brief Destructor of Entity
  virtual ~Entity();

  /// @brief Update the entity. This function is PURE VIRTUAL. You MUST implement it when extending from Entity.
  /// @param deltaTime Time elapsed since last frame draw.
  /// @return void
  virtual void update(float deltaTime) = 0;

  /// @brief Add an Entity as child to an Entity
  /// @param child The Entity you are adding as child
  /// @return void
  void addChild(Entity *child);
  /// @brief Remove this Entity as a child
  /// @param child Entity you are removing as child
  /// @return void
  void removeChild(Entity *child);

  /// @brief Add a texture to an Entity
  /// @param filePath string of local path to the texture
  /// @return void
  void addTexture(std::string filePath);
  /// @brief Remove the texture from an Entity
  /// @return void
  void removeTexture();
  /// @brief Getter for the parent of an Entity
  /// @return Parent of an Entity
  Entity *parent() { return _parent; };
  void setTextureColor(Color c);

  /// @brief Getter for the children of an Entity
  /// @return std::vector<Entity> of the children of an Entity
  const std::vector<Entity *> &children() { return _children; };
  /// @brief Getter for the guid of an Entity
  /// @return The guid of an Entity
  int guid() { return _guid; };
  Texture2D texture() { return _texture; };
  Color color() { return _textureColor; };
  Vector2 size() { return Vector2{(float)_texture.width, (float)_texture.height}; };

  /// @brief Position vector for an Entity
  Vector3 position;

protected:
  /// @brief Original position of Entity, not relative to the parent
  Vector3 _worldposition;

private:
    /// @brief Texture of an Entity
  Texture2D _texture;
  Color _textureColor;
  /// @brief Vector containing all the children of an Entity
  std::vector<Entity *> _children;
  /// @brief The parent of an Entity
  Entity *_parent;
  /// @brief Custom ID that is different for every instance of an Entity
  int _guid;
  /// @brief Custom ID that isn't tied to an Entity yet
  static int _nextGuid;
};

#endif