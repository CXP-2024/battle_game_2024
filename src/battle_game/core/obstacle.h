#pragma once
#include "battle_game/core/object.h"
#include "glm/glm.hpp"

namespace battle_game {
class Obstacle : public Object {
 public:
  Obstacle(GameCore *game_core,
           uint32_t id,
           glm::vec2 position,
           float rotation = 0.0f);
  [[nodiscard]] virtual bool IsBlocked(glm::vec2 p) const = 0;
  void Update() override;
  void Render() override;
  virtual std::pair<glm::vec2, glm::vec2> GetSurfaceNormal(glm::vec2 origin,
                                                           glm::vec2 terminus) {
    return std::make_pair(glm::vec2(0, 0), glm::vec2(0, 0));
  }

 protected:
  template <class BulletType, class... Args>
  void GenerateBullet(
      uint32_t id,
      uint32_t player_id,  // obstacle_index, using "unit" architechture
                      glm::vec2 position,
                      float rotation,
                      float damage_scale,
                      Args... args);
};

}  // namespace battle_game
