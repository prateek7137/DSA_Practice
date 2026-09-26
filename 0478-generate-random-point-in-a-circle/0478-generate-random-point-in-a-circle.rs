struct Solution {
    radius: f64,
    xc: f64,
    yc: f64,
}

impl Solution {
    fn new(radius: f64, x_center: f64, y_center: f64) -> Self {
        Self { radius, xc: x_center, yc: y_center }
    }

    fn rand_point(&self) -> Vec<f64> {
        loop {
            let x = (rand::random::<f64>() * 2.0 - 1.0) * self.radius;
            let y = (rand::random::<f64>() * 2.0 - 1.0) * self.radius;

            if x * x + y * y <= self.radius * self.radius {
                return vec![self.xc + x, self.yc + y];
            }
        }
    }
}