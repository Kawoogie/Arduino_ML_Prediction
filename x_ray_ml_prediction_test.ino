#include "RandomForest.h" // Load the header file with the model

// Initialize the model
Eloquent::ML::Port::RandomForestRegressor rfreg;

// Set up serial communication
void setup() {
    Serial.begin(115200);
    Serial.println("Begin");
}

void loop() {

    // Input data to the model
    float normalizedData[3] = {0.835905, 0.658466, 0.493595};

    Serial.print("Predicted Mean Energy (you should see '46.20': ");
    
    // Use the model to make a prediction with the input data. Then
    // output the prediction to the serial monitor
    Serial.println(rfreg.predict(normalizedData));

    delay(1000);
}