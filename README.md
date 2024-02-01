# Arduino_ML_Prediction

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/Kawoogie/Arduino_ML_Prediction">
    <img src="Screenshots/logo.png" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">Arduino_ML_Prediction</h3>

  <p align="center">
    This code provides an xample of using the tinyML gen package output from 
    Python to make machine learning predictions on an Arduino Nano 33 BLE Sense Lite.
    <br />
    <a href="https://github.com/Kawoogie/Arduino_ML_Prediction"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="#output">View Demo</a>
    ·
    <a href="https://github.com/Kawoogie/Arduino_ML_Prediction/issues">Report Bug</a>
    ·
    <a href="https://github.com/Kawoogie/Arduino_ML_Prediction/issues">Request Feature</a>
  </p>
</div>

## About The Project

This code provides an xample of using the tinyML gen package output from Python to make machine learning predictions on an Arduino Nano 33 BLE Sense Lite.

Here is the tinyML gen repository:
https://github.com/eloquentarduino/tinymlgen

The above repository uses Python to generate C code for running a machine learning model on a microprocessor. This is what generated the RandomForest.h model
included in this repository.

## Getting Started

To begin, the RandomForest.h header file and the x_ray_ml_prediction_test.ino file must be put into the same folder under the Arduino folder for the Arduino IDE.

The code should then be uploaded to an Arduino Nano 33 BLE.

One the sketch is uploaded, open the serial monitor. You should see the Arduino making a prediction from the preinput values on line 15.


## Code Overview

The header file containing the machine learning model needs to be imported.
   ```sh
   #include "RandomForest.h" // Load the header file with the model
   ```

The machine learning model is initialized from the included header file with this command:
   ```sh
   // Initialize the model
   Eloquent::ML::Port::RandomForestRegressor rfreg;
   ```

For this example, the model takes 3 float values as an input and returns a float value.

The three float values for the prediction are defined in line 15:
   ```sh
   float normalizedData[3] = {0.835905, 0.658466, 0.493595};
   ```

The model makes its prediction from these three float inputs and outputs a float value on line 21:
   ```sh
   Serial.println(rfreg.predict(normalizedData));
   ```

Where the prediction is being done with this command:
   ```sh
   rfreg.predict(normalizedData)
   ```

Note: Even though the serial monitor only outputs two decimal places, the predicted float value contains more significant figures.
More significant figures can be displayed by adjusting the number of significant figures to display in the serial monitor:
   ```sh
   Serial.println(rfreg.predict(normalizedData), sigfigs_int);
   ```
<!-- OUTPUT -->
## Output

Here is a screenshot showing the code running and the output in the serial monitor

<!-- PROJECT Screenshot -->
<br />
<div align="center">
  <a href="https://github.com/Kawoogie/Arduino_ML_Prediction">
    <img src="Screenshots/Code Running.png" alt="screenshot" >
  </a>
