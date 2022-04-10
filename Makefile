computus: computus.c
	$(CC) -w -o $@ $<

clean:
	rm -f computus

.PHONY: clean
