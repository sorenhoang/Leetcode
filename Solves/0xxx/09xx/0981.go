type value struct {
	val string
	ts  int
}

type TimeMap struct {
	hmap map[string][]value
}

func Constructor() TimeMap {
	return TimeMap{
		hmap: make(map[string][]value, 1),
	}
}

func (this *TimeMap) Set(key string, newValue string, timestamp int) {
	if values, ok := this.hmap[key]; ok {
		this.hmap[key] = append(values, value{val: newValue, ts: timestamp})
	} else {
		this.hmap[key] = []value{{val: newValue, ts: timestamp}}
	}
}

func (this *TimeMap) Get(key string, timestamp int) string {
	if values, ok := this.hmap[key]; ok {
		if values[len(values)-1].ts < timestamp {
			return values[len(values)-1].val
		}
		if values[0].ts > timestamp {
			return ""
		}

		l, r := 0, len(values)
		for r > l+1 {
			med := (l + r) / 2
			if values[med].ts > timestamp {
				r = med
			} else {
				l = med
			}
		}
		return values[l].val
	}
	return ""
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Set(key,value,timestamp);
 * param_2 := obj.Get(key,timestamp);
 */