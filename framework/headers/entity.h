#ifndef ENTITY_H
#define ENTITY_H

#include <assert.h>
#include <iostream>
#include <raylib.h>
#include <vector>

/// The base class for all entities in the game.
class Entity {
public:
  /// Default constructor.
  Entity();

  /// Virtual destructor.
  virtual ~Entity();

  /// Updates the entity's state.
  /// @param deltaTime The time elapsed since the last update.
  virtual void update(float deltaTime) = 0;

  /// Adds a child entity to this entity.
  /// @param child The child entity to add.
  void addChild(Entity *child);

  /// Removes a child entity from this entity.
  /// @param child The child entity to remove.
  void removeChild(Entity *child);

  /// Adds a texture to the entity.
  /// @param filePath The file path of the texture to add.
  void addTexture(const char *filePath);

  /// Removes the texture from the entity.
  void removeTexture();

  /// Gets the parent entity of this entity.
  /// @return The parent entity.
  Entity *parent() { return _parent; };

  /// Sets the color of the entity's texture.
  /// @param c The color to set.
  void setTextureColor(Color c);

  /// Gets the children entities of this entity.
  /// @return The children entities.
  const std::vector<Entity *> &children() { return _children; };

  /// Gets the globally unique identifier (GUID) of this entity.
  /// @return The GUID.
  int guid() { return _guid; };

  /// Gets the texture of the entity.
  /// @return The texture.
  Texture2D texture() { return _texture; };

  /// Gets the color of the entity's texture.
  /// @return The texture color.
  Color color() { return _textureColor; };

  /// Gets the size of the entity.
  /// @return The size.
  Vector2 size() { return Vector2{(float)_texture.width, (float)_texture.height}; };

  /// Adds a texture to the entity from an image.
  /// @param image The image to add as a texture.
  void addTextureFromImage(Image image);

  Vector3 position; ///< The position of the entity in 3D space.
  Vector3 rotation; ///< The rotation of the entity in 3D space.

protected:
  Vector3 _worldposition; ///< The world position of the entity.

private:
  Texture2D _texture;              ///< The texture of the entity.
  Color _textureColor;             ///< The color of the entity's texture.
  std::vector<Entity *> _children; ///< The children entities of this entity.
  Entity *_parent;                 ///< The parent entity of this entity.
  int _guid;                       ///< The globally unique identifier (GUID) of this entity.
  static int _nextGuid;            ///< The next available GUID for entities.
};

#endif