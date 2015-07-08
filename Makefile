SKETCHES = interrupts hc-sr04-intr hc-sr04-led interrupts sim800h

all:
	for d in $(SKETCHES); do $(MAKE) -C $$d; done

clean:
	-$(RM) -rf */build-uno
