let max(x y) <- if(x > y) x else y
let min(x y) <- if(x < y) x else y
let floor(x) <- x - (x%1)
let ceiling(x) <- if(floor(x) = x) x else floor(x + 1)
let sq(x) <- x * x
let pow(x y) <- if(y = 0) 0 else if(y = 1) x else x * pow(x y - 1)
let ilog(b n) <- if(n < b) 0 else ilog(b n/b) + 1.0
let fact(x) <- if(x = 1) x else x * fact(x - 1)
let choose(n r) <- fact(n) / (fact(r) * fact(n - r))
let sum(n) <- (n * (n + 1)) / 2
