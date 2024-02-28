#include <entity.h>

int Entity::_nextGuid = 0;

Entity::Entity()
{
  _guid = _nextGuid;
  _nextGuid++;

  _parent = nullptr;

  position = {0.0f, 0.0f, 0.0f};
}

Entity::~Entity()
{
  removeTexture();
}

void Entity::update(float deltaTime)
{
}

void Entity::addChild(Entity *child)
{
  if (child->_parent != nullptr)
  {
    std::cout << "has parent" << std::endl;
    child->_parent->removeChild(child);
  }
  // Set the current entity as the parent of the child.
  child->_parent = this;
  // Add the child to the list of children of the current entity.
  this->_children.push_back(child);

  std::cout << "added entity" << std::endl;
}

void Entity::removeChild(Entity *child)
{
  // Iterate through the list of children of the current entity.
  std::vector<Entity *>::iterator it = _children.begin();
  while (it != _children.end())
  {
    // Find the child by comparing their unique identifiers (_guid).
    if ((*it)->_guid == child->_guid)
    {
      // Disconnect the child from the current entity by setting its parent to nullptr.
      child->_parent = nullptr;
      // Remove the child from the list of children and update the iterator.
      it = _children.erase(it);
    }
    else
    {
      // Move to the next child in the list.
      ++it;
    }
  }
}

void Entity::removeTexture()
{
  if (IsTextureReady(this->_texture))
    UnloadTexture(this->_texture);
}

void Entity::addTexture(char *filePath)
{
  removeTexture();
  if (IsPathFile(filePath))
    this->_texture = LoadTexture(filePath);
}

void Entity::setTextureColor(Color c)
{
  this->_textureColor = c;
}