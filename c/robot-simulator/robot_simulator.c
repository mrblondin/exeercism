#include "robot_simulator.h"

static robot_status_t move_coordinates[4] = { 
  { DIRECTION_NORTH, {0, 1} },
  { DIRECTION_EAST, {1, 0} },
  { DIRECTION_SOUTH, {0, -1} },
  { DIRECTION_WEST, {-1, 0} }
};

robot_status_t robot_create(robot_direction_t direction, int x, int y){
  return (robot_status_t){direction, {x, y}};
}

void robot_move(robot_status_t *robot, const char *commands){
  while(*commands){
    switch(*commands++) {
      case 'A':
        robot->position.x += move_coordinates[robot->direction].position.x;
        robot->position.y += move_coordinates[robot->direction].position.y;
        break;
      case 'R':
        robot->direction = (robot->direction + 1) % 4;
        break;
      case 'L':
        robot->direction = (robot->direction + 3) % 4;
        break;
    }
  }
}
