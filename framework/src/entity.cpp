#include <entity.h>

int Entity::_nextGuid = 0;

Entity::Entity() {
  _guid = _nextGuid++;

  _parent = nullptr;

  position = {0.0f, 0.0f, 0.0f};
  rotation = {0.0f, 0.0f, 0.0f};

  _texture = {0};

  _textureColor = WHITE;
}

Entity::~Entity() {
  removeTexture();
}

void Entity::addChild(Entity *child) {
  if (child->_parent != nullptr) {
    std::cout << "has parent" << std::endl;
    child->_parent->removeChild(child);
  }
  // Set the current entity as the parent of the child.
  child->_parent = this;
  // Add the child to the list of children of the current entity.
  this->_children.push_back(child);

  std::cout << "Added entity with GUID: " << child->_guid
            << " at position: (" << child->position.x << ", " << child->position.y << ", " << child->position.z << ")" << std::endl;
}

void Entity::removeChild(Entity *child) {

  std::vector<Entity *>::iterator it = _children.begin();
  while (it != _children.end()) {       // Iterate through the list of children of the current entity.
    if ((*it)->_guid == child->_guid) { // Find the child by comparing their unique identifiers (_guid).
      child->_parent = nullptr;         // Disconnect the child from the current entity by setting its parent to nullptr.
      it = _children.erase(it);         // Remove the child from the list of children and update the iterator.
    } else {
      ++it; // Move to the next child in the list.
    }
  }
}

void Entity::removeTexture() {
  if (IsTextureReady(this->_texture)) {
    UnloadTexture(this->_texture);
    std::cout << "##################\nUnloaded Texture\n##################" << std::endl;
  }
}

void Entity::addTexture(const char *filePath) {
  removeTexture();
  if (IsPathFile(filePath))
    this->_texture = LoadTexture(filePath);

  if (_texture.id == 0) {
    perror("Failed to load texture: ");
  }
}

void Entity::addTextureFromImage(Image image) {
  this->_texture = LoadTextureFromImage(image);
}

void Entity::setTextureColor(Color c) {
  this->_textureColor = c;
}