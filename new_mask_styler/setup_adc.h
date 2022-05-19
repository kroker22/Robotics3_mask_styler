/*
 * setup_adc.h
 *
 * Created: 2022-05-19 오후 1:00:27
 *  Author: hongki
 */ 


#ifndef SETUP_ADC_H_
#define SETUP_ADC_H_

 void ADC_INIT();
 double ADC_PSD_GET(); //psd
 double calc_psd();

 double ADC_CDS_GET();
 double calc_cds(); // cds


 double ADC_IR_GET(); // 적외선센서
 double calc_IR();

 double ADC_lm35_GET();
 double calc_lm35(); // 이거 온습도 섞여있는거임


 double ADC_POTEN_GET(); //  가변저항




 
 // 지금 치면서 생각하는건데 이거 반환값이 행렬이여야 할거같음


 // 행렬로 넘겨준 값이 필터함수 내부에있는 배열이나 구조체에 들어가면 함수 내부 규칙에 의해서 특정 값이 반환
 // 반환된 값이 interrupt나 polling을 일어나게 하면 될듯

 double low_pass_filter(double adc_values_1);
 double high_pass_filter(double adc_values_2);

 double MAF(double adc_values_3);	//psd sensor


 // 사실 지금 filter 부분이거 리턴을 뭘로해야할지 모르겠어서 void 로 했음
 // 센서확정짓고 좀더 공부하면 이거 void 말고 double 이나 float로 하고싶은데



#endif /* SETUP_ADC_H_ */