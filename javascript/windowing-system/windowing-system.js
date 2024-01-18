// @ts-check

/**
 * Implement the classes etc. that are needed to solve the
 * exercise in this file. Do not forget to export the entities
 * you defined so they are available for the tests.
 */

/**
 * Define Size for storing the dimensions of the window, constructor
 * @param {number} width
 * @param {number} height
 */
export function Size(width = 80, height = 60) {
  this.width = width;
  this.height = height;
}

/**
 * Redefine Size for storing the dimensions of the window, methon
 * @param {number} newWidth
 * @param {number} newHeight
 */
Size.prototype.resize = function(newWidth, newHeight) {
  this.width = newWidth;
  this.height = newHeight;
}

/**
 * Define Position to store a window position, constructor
 * @param {number} x 
 * @param {number} y
 */
export function Position(x = 0, y = 0) {
  this.x = x;
  this.y = y;
}

/**
 * Redefine Position to store a window position, method
 * @param {number} newX 
 * @param {number} newY
 */
Position.prototype.move = function(newX, newY) {
  this.x = newX;
  this.y = newY;
}

export class ProgramWindow {
  constructor() {
    this.screenSize = new Size(800, 600);
    this.size = new Size();
    this.position = new Position();
  }

  resize = (newSize) => {
    const maxWidth = this.screenSize.width - this.position.x;
    const maxHeigt = this.screenSize.height - this.position.y;

    const newWidth = newSize.width < 1 ? 1:
      maxWidth > newSize.width ? newSize.width : maxWidth; 
    const newHeight = newSize.height < 1 ? 1:
      maxHeigt > newSize.height ? newSize.height : maxHeigt; 

    this.size.resize(newWidth, newHeight);
  }

  move = (newPosition) => {
    const maxX = this.screenSize.width - this.size.width;
    const maxY = this.screenSize.height - this.size.height;

    const newX = newPosition.x < 0 ? 0 :
      maxX > newPosition.x ? newPosition.x : maxX;
    const newY = newPosition.y < 0 ? 0 :
      maxY > newPosition.y ? newPosition.y : maxY;

    this.position.move(newX, newY)
  }
}

/**
 * Change window to some defaults
 * @param {ProgramWindow} programWindow
 * return {ProgramWindow}
 */
export const changeWindow = programWindow => {
  programWindow.resize(new Size(400, 300));
  programWindow.move(new Position(100, 150));
  return programWindow;
}
