#include "GateY.hpp"
#include "Variable.hpp"
#include <thread>
#include <chrono>
#include <cmath>

/*
TODO:

- Use broadcast for websocket so all clients get updates
- Allow only one connection for the moment
*/

int main() {
    std::chrono::milliseconds dura(100);
    gatey::global = std::make_shared<gatey::GateY>();


    //const std::size_t SIZE = 32;
    //std::array<std::array<double, SIZE>, SIZE> field = { { 0.0 } };
    //std::tuple<int, std::string> tuple;
    //WriteVariable<decltype(field)> gField("field");
    //WriteVariable<decltype(tuple)> gTuple("tuple");

    //field[SIZE / 2][SIZE / 2] = 100000.0;
    //double alpha = 1.0;
    //double dt = 1.0 / 30;
    //while (true) {
    //	char c;
    //	std::cin >> c;

    //	tuple = std::make_tuple(1, std::string("Hello World"));
    //	gTuple.set(tuple);

    //	for (unsigned int step = 0; step < 100; ++step) {
    //		std::this_thread::sleep_for(dura);

    //		decltype(field) copy = { { 0.0 } };
    //		for (std::size_t x = 1; x < SIZE - 1; ++x) {
    //			for (std::size_t y = 1; y < SIZE - 1; ++y) {
    //				//du/dt = alpha laplace u
    //				//du = dt * alpha laplace u
    //				//u' = u + dt * alpha laplace u
    //				double laplace = field[x - 1][y] + field[x + 1][y] + field[x][y - 1] + field[x][y + 1] - 4 * field[x][y];
    //				copy[x][y] = field[x][y] + alpha * dt * laplace;
    //			}
    //		}
    //		field = copy;
    //		gField.set(field);
    //	}
    //}


    
    gatey::WriteVariable<std::tuple<float, float>> gF("y");
    gatey::ReadVariable<float> gDt("dt", 0.01f);
    gatey::ReadVariable<float> gC("c", 1.0f);


    float time = 0.0f;
    while (true) {
        float y = gC.get() * std::sin(time);
        gF.set(std::make_pair(time, y));
        time += gDt.get();
        std::this_thread::sleep_for(dura);
    }


 //   gateY.start();

    //WriteVariable<std::vector<float>> gXs("xs");
 //   ReadVariable<float> gFreq("freq", 1.0f);

 //   std::chrono::milliseconds dura(20);

 //   std::vector<float> xs(4000);
 //   for(std::size_t i = 0; i < 4000; ++i)
 //       xs[i] = i;

 //   float time = 0;
 //   while (true) {
 //       std::this_thread::sleep_for(dura);
 //       float delta = 1.0f / gFreq.get();
 //       gXs.set(xs);
 //       time += delta;
 //   }

    return 0;


}

