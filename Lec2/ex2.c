#include<stdio.h>
#include<math.h>

typedef struct point{
    double x;
    double y;
} point_t;

typedef struct circle{
    point_t center;
    double radius;
} circle_t;

int is_in_circle(const point_t gv_point, const circle_t gv_circle){
    double check = pow((gv_point.x - gv_circle.center.x),2) + pow((gv_point.y - gv_circle.center.y),2); 
    if(check <= pow((gv_circle.radius),2))
        return 1;
    else    
        return 0;
}

// int is_in_circle(point_t *p, circle_t *c)
// {
//     double x_dist, y_dist;
//         x_dist = p->x - c->center.x;
//         y_dist = p->y - c->center.y;
    
//     return (x_dist * x_dist + y_dist * y_dist <= c->radius * c->radius);
// }

int main(){
    point_t pt;
    circle_t cir;
    pt.x = 2;
    pt.y = 4;

    cir.center.x = 0;
    cir.center.y = 0;
    cir.radius = 2;

    // printf("Ket qua: %d", is_in_circle(&pt, &cir));

    printf("Ket qua: %d", is_in_circle(pt, cir));
    
    return 0;
}