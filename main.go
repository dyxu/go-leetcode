package main

import (
	"fmt"
)

func complexNumberMultiply(a string, b string) string {
	ra, ib, rc, id := 0, 0, 0, 0
	fmt.Sscanf(a, "%d+%di", &ra, &ib)
	fmt.Sscanf(b, "%d+%di", &rc, &id)

	return fmt.Sprintf("%d+%di", ra*rc-ib*id, ra*id+ib*rc)
}

func main() {
	fmt.Printf("%s\n", complexNumberMultiply("1+-1i", "1+-1i"))
}
