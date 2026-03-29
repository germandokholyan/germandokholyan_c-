#include "ConstGenerator.h"
miit::algebra::ConstGenerator::ConstGenerator(int val)
    : value(val)
{
}
int miit::algebra::ConstGenerator::generate()
{
    return value;
}
