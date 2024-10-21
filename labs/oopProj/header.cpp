class integral {
	public:
		void calculate();
		void getData();
		void getVariant();
		int variant = 0;
		double from, to, intervals = 0;
		double lastResult = 0;
	private:
		double countIntegralBasic();
		double integratedFunc(double x);
};