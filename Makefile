SKETCHES = interrupts hc-sr04-intr hc-sr04-led sim800h sim800h-tcp

.PHONY: subdirs $(SKETCHES)

all: $(SKETCHES)

$(SKETCHES):
	$(MAKE) -C $@

clean:
	-$(RM) -r */build-uno
