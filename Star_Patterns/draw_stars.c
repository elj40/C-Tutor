void draw_cross(int size) {
    for (int y = size; y >= 0; y--) {
        for (int x = 0; x < size; x++) {
            if (y == x || y == -x + size) {
                printf("* ");
            } else {
                printf("  ");
            }

        }
        printf("\n");
    }
}

void draw_circle(int size, int radius) {
    for (int y = size; y >= 0; y--) {
        for (int x = 0; x < size; x++) {
            int center_x = x - size/2;
            int center_y = y - size/2;
            if (center_x*center_x + center_y*center_y <= radius*radius) {
                printf("* ");
            } else {
                printf("  ");
            }

        }
        printf("\n");
    }
}
