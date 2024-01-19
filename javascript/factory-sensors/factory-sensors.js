// @ts-check

const ERROR_HUMIDITY = 70;
const OVERHEATING_TEMP = 500;
const ALERT_TEMP = 600;

export class ArgumentError extends Error {}

export class OverheatingError extends Error {
  constructor(temperature) {
    super(`The temperature is ${temperature} ! Overheating !`);
    this.temperature = temperature;
  }
}

/**
 * Check if the humidity level is not too high.
 *
 * @param {number} humidityPercentage
 * @throws {Error}
 */
export const checkHumidityLevel = humidityPercentage => {
  if(humidityPercentage >= ERROR_HUMIDITY) 
    throw new Error("Error");
}

/**
 * Check if the temperature is not too high.
 *
 * @param {number|null} temperature
 * @throws {ArgumentError|OverheatingError}
 */
export const reportOverheating = temperature => {
  const temp = Number(temperature);
  if (!temp)
    throw new ArgumentError();
  else if (temp > OVERHEATING_TEMP)
    throw new OverheatingError(temp);
}

/**
 *  Triggers the needed action depending on the result of the machine check.
 *
 * @param {{
 * check: function,
 * alertDeadSensor: function,
 * alertOverheating: function,
 * shutdown: function
 * }} actions
 * @throws {ArgumentError|OverheatingError|Error}
 */
export const monitorTheMachine = actions => {
  try {
    actions.check();
  } catch (error) {
    if (error instanceof ArgumentError)
      actions.alertDeadSensor();
    else if (error instanceof OverheatingError)
      error.temperature < ALERT_TEMP ? actions.alertOverheating() : actions.shutdown();
    else
      throw error;
  }
}
