let max(x y) <- if(x > y) x else y
let min(x y) <- if(x < y) x else y
let floor(x) <- x - (x%1)
let ceiling(x) <- if(floor(x)=x) x else floor(x+1)
let sq(x) <- x * x
let pow(x y) <- if(y = 0) 0 else if(y = 1) x else x * pow(x y-1)
let ilog(b n) <- if(n<b) 0 else log(b n/b) + 1.0
let pi <- 3.14159
let e <- 2.71828