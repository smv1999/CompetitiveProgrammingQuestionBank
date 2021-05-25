class Rectangle {
    constructor(w, h) {
        this.w = w;
        this.h = h;
    }
}

/*
 *  Write code that adds an 'area' method to the Rectangle class' prototype
 */
Rectangle.prototype.area= function(){
     return this.w * this.h;
}
/*
 * Create a Square class that inherits from Rectangle and implement its class constructor
 */
//inherit from rectangle
class Square extends Rectangle {
    //create Square constructor
    constructor (a){
        //call constructor from Rectangle class and insert value
        super (a,a);
    }
}
