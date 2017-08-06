package student_attendance_record_i

// 551. Student Attendance Record I

func checkRecord(s string) bool {
	cnt, prev := 0, 0
	for _, s := range s {
		if s == 'A' {
			cnt++
			if cnt > 1 {
				return false
			}
		}
		if s == 'L' {
			prev++
			if prev > 2 {
				return false
			}
		} else {
			prev = 0
		}
	}

	return true
}
