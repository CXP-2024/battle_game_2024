#pragma once
#include "battle_game/core/obstacle.h"

namespace battle_game::obstacle {
class Block : public Obstacle { //Nahida
 public:
  Block(GameCore *game_core,
        uint32_t id,
        glm::vec2 position,
        float rotation = 0.0f,
        glm::vec2 scale = glm::vec2{1.0f, 1.0f});

 private:
  [[nodiscard]] bool IsBlocked(glm::vec2 p) const override;
  void Update() override;
  void Render() override;
  void Nahida_Fire();
  void Rotation();
  glm::vec2 scale_{2.0f, 2.0f};
  int fire_count_down_{0};
};

class FurinaBlock : public Obstacle { //Furina
 public:
  FurinaBlock(GameCore *game_core,
         uint32_t id,
         glm::vec2 position,
         float rotation = 0.0f,
         glm::vec2 scale = glm::vec2{1.0f, 1.0f});

 private:
  [[nodiscard]] bool IsBlocked(glm::vec2 p) const override;
  void Render() override;
  void Update() override;
  void Furina_Fire();
  void Block_Move();
  glm::vec2 scale_{2.0f};
  glm::vec2 position_ini{};
  bool go_right_{true};
  int fire_count_down_{0};
};

class Block3 : public Obstacle {
 public:
  Block3(GameCore *game_core,
         uint32_t id,
         glm::vec2 position,
         float rotation = 0.0f,
         glm::vec2 scale = glm::vec2{1.0f, 1.0f});

 private:
  [[nodiscard]] bool IsBlocked(glm::vec2 p) const override;
  void Render() override;
  glm::vec2 scale_{1.5f};
};

}  // namespace battle_game::obstacle
