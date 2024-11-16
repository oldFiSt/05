#include "Ball.hpp"
#include <cmath>


Ball::Ball(double r, const Point& c, const Color& col, bool collidable):radius(r), center(c), color(col),velocity(0,0), isCollidable(collidable){
    massa = (M_PI * pow(radius, 3) * 4)/3.0;
}
/**
 * Задает скорость объекта
 * @param velocity новое значение скорости
 */
void Ball::setVelocity(const Velocity& newvelocity) {
    velocity = newvelocity;
}

/**
 * @return скорость объекта
 */
Velocity Ball::getVelocity() const {
    return velocity;
}

/**
 * @brief Выполняет отрисовку объекта
 * @details объект Ball абстрагирован от конкретного
 * способа отображения пикселей на экране. Он "знаком"
 * лишь с интерфейсом, который предоставляет Painter
 * Рисование выполняется путем вызова painter.draw(...)
 * @param painter контекст отрисовки
 */
void Ball::draw(Painter& painter) const {
    painter.draw(center, radius, color);
}

/**
 * Задает координаты центра объекта
 * @param newcenter новый центр объекта
 */
void Ball::setCenter(const Point& newcenter) {
    center = newcenter;
}

/**
 * @return центр объекта
 */
Point Ball::getCenter() const {
    return center;
}

/**
 * @brief Возвращает радиус объекта
 * @details обратите внимание, что метод setRadius()
 * не требуется
 */
double Ball::getRadius() const {
    return radius;
}

/**
 * @brief Возвращает массу объекта
 * @details В нашем приложении считаем, что все шары
 * состоят из одинакового материала с фиксированной
 * плотностью. В этом случае масса в условных единицах
 * эквивалентна объему: PI * radius^3 * 4. / 3.
 */
double Ball::getMass() const {
    double mass = (M_PI * pow(radius, 3) * 4) / 3;
    return mass;
}

bool Ball::getIsCollidable() const{
    return isCollidable;
}
