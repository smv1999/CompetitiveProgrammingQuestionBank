/*
 * Implement a Polygon class with the following properties:
 * 1. A constructor that takes an array of integer side lengths.
 * 2. A 'perimeter' method that returns the sum of the Polygon's side lengths.
 */
class Polygon{
    constructor(sides){
        this.sides=sides
    }
    perimeter(){
        return this.sides.reduce(function add(a,b){ return a+b;})
    }
}
