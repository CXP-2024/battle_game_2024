#pragma once
#include "battle_game/core/bullet.h"

namespace battle_game::bullet {
class CannonBall : public Bullet {
 public:
  CannonBall(GameCore *core,
             uint32_t id,
             uint32_t unit_id,
             uint32_t player_id,
             glm::vec2 position,
             float rotation,
             float damage_scale,
             glm::vec2 velocity);
  ~CannonBall() override;
  void Render() override;
  void Update() override;

 private:
  glm::vec2 velocity_{};
};

class NahidaBullet : public Bullet {
 public:
  NahidaBullet(GameCore *core,
               uint32_t id,
               uint32_t unit_id,
               uint32_t player_id,
               glm::vec2 position,
               float rotation,
               float damage_scale,
               glm::vec2 velocity);
  ~NahidaBullet() override;
  void Render() override;
  void Update() override;

 private:
  glm::vec2 velocity_{};
};

class FurinaBullet : public Bullet {
 public:
  FurinaBullet(GameCore *core,
               uint32_t id,
               uint32_t unit_id,
               uint32_t player_id,
               glm::vec2 position,
               float rotation,
               float damage_scale,
               glm::vec2 velocity);
  ~FurinaBullet() override;
  void Render() override;
  void Update() override;

 private:
  glm::vec2 velocity_{};
};
}  // namespace battle_game::bullet
