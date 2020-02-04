
module SISTEMA (
	clk_clk,
	ldr_external_interface_sclk,
	ldr_external_interface_cs_n,
	ldr_external_interface_dout,
	ldr_external_interface_din,
	reset_reset_n);	

	input		clk_clk;
	output		ldr_external_interface_sclk;
	output		ldr_external_interface_cs_n;
	input		ldr_external_interface_dout;
	output		ldr_external_interface_din;
	input		reset_reset_n;
endmodule
