#include "battle_game/core/obstacles/block.h"

#include "battle_game/core/bullets/bullets.h"
#include "battle_game/core/game_core.h"
#include "battle_game/graphics/graphics.h"

namespace battle_game::obstacle {

Block::Block(GameCore *game_core,
             uint32_t id,
             glm::vec2 position,
             float rotation,
             glm::vec2 scale)
    : Obstacle(game_core, id, position, rotation) {
}

bool Block::IsBlocked(glm::vec2 p) const {
  p = WorldToLocal(p);
  return p.x <= scale_.x && p.x >= -scale_.x && p.y <= scale_.y &&
         p.y >= -scale_.y;
}

void Block::Nahida_Fire() {
  if (fire_count_down_ == 0) {
    auto velocity1 = Rotate(glm::vec2{0.0f, 20.0f}, rotation_);
    GenerateBullet<bullet::NahidaBullet>(
        id_ + 100, 100, position_ + Rotate({0.0f, 1.8f}, rotation_),
        rotation_, 1.0f,
        velocity1);                // add player_id (100) and damage_scale (1.0f)
    auto velocity2 = Rotate(glm::vec2{0.0f, 20.0f}, rotation_ + 1.57);
    GenerateBullet<bullet::NahidaBullet>(
        id_ + 100, 100, position_ + Rotate({0.0f, 1.8f}, rotation_ + 1.57), rotation_,
        1.0f,
        velocity2);                // add player_id (100) and damage_scale (1.0f)
    auto velocity3 = Rotate(glm::vec2{0.0f, 20.0f}, rotation_ - 1.57);
    GenerateBullet<bullet::NahidaBullet>(
        id_ + 100, 100, position_ + Rotate({0.0f, 1.8f}, rotation_ - 1.57),
        rotation_, 1.0f,
        velocity3);               // add player_id (100) and damage_scale (1.0f)
    auto velocity4 = Rotate(glm::vec2{0.0f, 20.0f}, rotation_ + 3.14);
    GenerateBullet<bullet::NahidaBullet>(
        id_ + 100, 100, position_ + Rotate({0.0f, 1.8f}, rotation_ + 3.14),
        rotation_, 1.0f,
        velocity4);               // add player_id (100) and damage_scale (1.0f)
        fire_count_down_ = 0.2 * 60;  // Fire interval 0.2 second.
  }
  if (fire_count_down_) {
    fire_count_down_--;
  }
}

void Block::Update() {
  Nahida_Fire();
  Rotation();
}

void Block::Rotation() {
  rotation_ += 0.01f;
  if (rotation_ > glm::pi<float>() * 2.0f) {
    rotation_ -= glm::pi<float>() * 2.0f;
  }
}

void Block::Render() {
  battle_game::SetColor(glm::vec4{1.0f, 1.0f, 1.0f, 1.0f});
  battle_game::SetTexture(BATTLE_GAME_ASSETS_DIR "textures/Nahida.png");
  battle_game::SetTransformation(position_, rotation_, scale_);
  battle_game::DrawModel(0);
}

               //block2
FurinaBlock::FurinaBlock(GameCore *game_core,
    uint32_t id,
    glm::vec2 position,
    float rotation,
    glm::vec2 scale)
    : Obstacle(game_core, id, position, rotation), position_ini(position) {
}

bool FurinaBlock::IsBlocked(glm::vec2 p) const {
  p = WorldToLocal(p);
  return p.x * p.x + p.y * p.y <= scale_.length() * scale_.length();
}

void FurinaBlock::Render() {
  battle_game::SetColor(glm::vec4{1.0f, 1.0f, 1.0f, 1.0f});
  battle_game::SetTexture(BATTLE_GAME_ASSETS_DIR "textures/Furina.png"); //furina
  battle_game::SetTransformation(position_, rotation_, scale_);
  battle_game::DrawModel(0);
}

void FurinaBlock::Update() {
  Furina_Fire();
  Block_Move();
}

void FurinaBlock::Block_Move() {
  if (go_right_) {
    position_.x += 0.01f;
    if (position_.x > position_ini.x + 1.0f) {
	  go_right_ = false;
	}
  }
  else {
	position_.x -= 0.01f;
    if (position_.x < position_ini.x - 1.0f) {
	  go_right_ = true;
    }
  }
}

void FurinaBlock::Furina_Fire() {
  if (fire_count_down_ == 0) {
    float velocity = 5.0f;
    float scaler = scale_.x + 0.2f;
    auto velocity1 = Rotate(glm::vec2{0.0f, velocity}, rotation_);
    GenerateBullet<bullet::FurinaBullet>(
        id_ + 101, 100, position_ + Rotate({0.0f, scaler}, rotation_),
        rotation_,
        1.0f,
        velocity1);  // add player_id (100) and damage_scale (1.0f)
    auto velocity2 = Rotate(glm::vec2{0.0f, velocity}, rotation_ + 1.57);
    GenerateBullet<bullet::FurinaBullet>(
        id_ + 101, 100, position_ + Rotate({0.0f, scaler}, rotation_ + 1.57),
        rotation_, 1.0f,
        velocity2);  // add player_id (100) and damage_scale (1.0f)
    auto velocity3 = Rotate(glm::vec2{0.0f, velocity}, rotation_ - 1.57);
    GenerateBullet<bullet::FurinaBullet>(
        id_ + 101, 100, position_ + Rotate({0.0f, scaler}, rotation_ - 1.57),
        rotation_, 1.0f,
        velocity3);  // add player_id (100) and damage_scale (1.0f)
    auto velocity4 = Rotate(glm::vec2{0.0f, velocity}, rotation_ + 3.14);
    GenerateBullet<bullet::FurinaBullet>(
        id_ + 101, 100, position_ + Rotate({0.0f, scaler}, rotation_ + 3.14),
        rotation_, 1.0f,
        velocity4);
    auto velocity5 = Rotate(glm::vec2{0.0f, velocity}, rotation_ + 0.785);
    GenerateBullet<bullet::FurinaBullet>(
        id_ + 101, 100, position_ + Rotate({0.0f, scaler}, rotation_ + 0.785),
		rotation_, 1.0f,
		velocity5);  // add player_id (100) and damage_scale (1.0f)
    auto velocity6 = Rotate(glm::vec2{0.0f, velocity}, rotation_ - 0.785);
    GenerateBullet<bullet::FurinaBullet>(
        id_ + 101, 100, position_ + Rotate({0.0f, scaler}, rotation_ - 0.785),
        rotation_, 1.0f, velocity5);
    auto velocity7 = Rotate(glm::vec2{0.0f, velocity}, rotation_ + 2.355);
    GenerateBullet<bullet::FurinaBullet>(
        id_ + 101, 100, position_ + Rotate({0.0f, scaler}, rotation_ + 2.355),
		rotation_, 1.0f,
		velocity7);  // add player_id (100) and damage_scale (1.0f)
    auto velocity8 = Rotate(glm::vec2{0.0f, velocity}, rotation_ - 2.355);
    GenerateBullet<bullet::FurinaBullet>(
        id_ + 101, 100, position_ + Rotate({0.0f, scaler}, rotation_ - 2.355),
		rotation_, 1.0f, velocity8);
    // add player_id (100) and damage_scale (1.0f)
    fire_count_down_ = 1 * 60;  // Fire interval 0.5 second.
  }
  if (fire_count_down_) {
    fire_count_down_--;
  }
}

			   // block3, cycling
namespace {
uint32_t new_model = 0xffffffffu;
}  // namespace
Block3::Block3(GameCore *game_core,
               uint32_t id,
               glm::vec2 position,
               float rotation,
               glm::vec2 scale)
    : Obstacle(game_core, id, position, rotation) {
  if (!~new_model) {
    auto mgr = AssetsManager::GetInstance();
    {
      std::vector<ObjectVertex> body_vertices;
      std::vector<uint32_t> body_indices;
      const int precision = 60;
      const float inv_precision = 1.0f / float(precision);
      for (int i = 0; i < precision; i++) {
        auto theta = (float(i) + 0.5f) * inv_precision;
        theta *= glm::pi<float>() * 2.0f;
        auto sin_theta = std::sin(theta);
        auto cos_theta = std::cos(theta);
        body_vertices.push_back({{sin_theta * 0.9f, cos_theta * 0.9f},
                                 {0.0f, 0.0f},
                                 {1.0f, 1.0f, 1.0f, 1.0f}});
        body_indices.push_back(i);
        body_indices.push_back((i + 1) % precision);
        body_indices.push_back(precision);
      }
      new_model = mgr->RegisterModel(body_vertices, body_indices);
    }
  }
}

bool Block3::IsBlocked(glm::vec2 p) const { //circle boudary
	p = WorldToLocal(p);
  return p.x * p.x + p.y * p.y <= scale_.length() * scale_.length();
}

void Block3::Render() {
  battle_game::SetColor(glm::vec4{1.0f, 1.0f, 1.0f, 1.0f});
  battle_game::SetTexture(0);
  battle_game::SetTransformation(position_, rotation_, scale_);
  battle_game::DrawModel(new_model);
}
}  // namespace battle_game::obstacle
