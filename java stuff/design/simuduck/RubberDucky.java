package design.simuduck;

public class RubberDucky extends Duck {
    
    RubberDucky() {
        /**
         * Initializing the behaviours 
         * This not good since  we r programming to implementations, later will improve
         */
        flyBehaviour = new FlyBehaviour() {
            @Override
            public void fly() {
                System.out.println("I can't fly vro");
            }
        };

        quackBehaviour = new QuackBehaviour() {
            @Override
            public void quack() {
                System.out.println("squeeeeeeeeeeek");
            }
        };
    }

    @Override
    public void info() {
        System.out.println("Rubber ducky");
    }
}
